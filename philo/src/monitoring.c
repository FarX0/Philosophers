/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:43:14 by tfalchi           #+#    #+#             */
/*   Updated: 2024/07/17 18:46:22 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	Monitor(t_data *data)
{
	if (create_threads(data))
		return ;
	if (pthread_create(&data->undertaker, NULL, check_life, data))
		return ;
	pthread_join(data->undertaker, NULL);
	(void)get_gameover(data, true);
}

t_bool	check_food(t_data *data, int id, int add)
{
	(void)id;
	if (data->meals_count == -1)
		return (false);
	pthread_mutex_lock(&data->fed);
	data->nb_fed += add;
	if (data->nb_fed == data->number_of_philosophers)
		return (true);
	pthread_mutex_unlock(&data->fed);
	return (false);
}

void	*check_life(void *da)
{
	t_data		*data;
	t_philo		*p;

	data = (t_data *)da;
	p = data->first_philo;
	while (!get_gameover(data, false))
	{
		if (check_food(data, p->id, 0) == true)
		{
			ft_mutex_write(p, "each philosopher is satisfied");
			(void)get_gameover(data, true);
			return (NULL);
		}
		if ((int)(get_current_time() - p->last_meal) >= data->time_to_die)
		{
			ft_mutex_write(p, "has died of hunger.");
			printf("%zu %d died\n", get_current_time(), p->id);
			(void)get_gameover(data, true);
			return (NULL);
		}
		if (p->right_philo)
			p = p->right_philo;
	}
	return (NULL);
}

// void	*check_life(void *da)
// {
// 	t_data		*data;
// 	int			j;

// 	data = (t_data *)da;
// 	j = data->nb_fork;
// 	while (j != -1 && go_on_change(data, FALSE) == TRUE)
// 	{
// 		j = 0;
// 		check_food(data, j, 0);
// 		while (j < data->nb_fork)
// 		{
// 			data->thrds[j].philo->life_left.time_since = ft_get_time(
// 					&data->thrds[j].philo->life_left, data);
// 			if (data->thrds[j].philo->life_left.time_since > data->time_to_die)
// 			{
// 				go_on_change(data, TRUE);
// 				print_action(data, DIED, j, ft_get_time(&data->time, data));
// 				return (NULL);
// 			}
// 			j++;
// 		}
// 	}
// 	return (NULL);
// }
// void	check_food(t_data *data, int id, int add)
// {
// 	int		i;
// 	int		nb_fed;

// 	i = 0;
// 	nb_fed = 0;
// 	pthread_mutex_lock(&data->nb_eaten_mutex);
// 	data->thrds[id].philo->left_to_eat -= add;
// 	if (data->thrds[id].philo->left_to_eat == 0)
// 	{
// 		data->thrds[id].philo->overfed = TRUE;
// 		while (i < data->nb_philo)
// 		{
// 			if (data->thrds[i].philo->overfed == TRUE)
// 				nb_fed++;
// 			i++;
// 		}
// 		if (nb_fed == data->nb_philo)
// 		{
// 			print_action(data, FED, id, ft_get_time(&data->time, data));
// 			go_on_change(data, TRUE);
// 		}
// 	}
// 	pthread_mutex_unlock(&data->nb_eaten_mutex);
// }
// int	check_meals(t_data *data)
// {
// 	t_philo	*p;

// 	if (data->meals_count == -1)
// 		return (0);
// 	p = data->first_philo;
// 	if (p->meals_eaten < data->meals_count)
// 		return (0);
// 	if (p->right_philo)
// 		p = p->right_philo;
// 	while (p != data->first_philo)
// 	{
// 		if (p->meals_eaten < data->meals_count)
// 			return (0);
// 		if (p->right_philo)
// 			p = p->right_philo;
// 	}
// 	return (1);
// }

// t_philo	*check_philo(t_data *data)
// {
// 	t_philo	*p;
	
// 	pthread_mutex_lock(&data->p_mutex);
// 	p = data->first_philo;
// 	if ((int)(get_current_time() - p->last_meal) >= data->time_to_die)
// 		return (p);
// 	if (p->right_philo)
// 		p = p->right_philo;

// 	while (p != data->first_philo)
// 	{
// 		if ((int)(get_current_time() - p->last_meal) >= data->time_to_die)
// 			return (p);
// 		if (p->right_philo)
// 			p = p->right_philo;		
// 	}
// 	pthread_mutex_unlock(&data->p_mutex);
// 	return (NULL);
// }

