/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:45:02 by lebartol          #+#    #+#             */
/*   Updated: 2024/07/08 15:37:47 by lebartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	if (philo->id % 2)
		philo_sleep(philo);
	while (!philo->data->game_over)
	{
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}

//TO DO spostare questa cosa direttamente in initialize_table()
int create_threads(t_data *data)
{
	t_philo *p = data->first_philo;
	if (create_philo_routine(p))
		return (1);
	p = p->right_philo;
	while (p != data->first_philo)
	{
		if (create_philo_routine(p))
			return (1);
		p = p->right_philo;
	}
	return (0);
}

int create_philo_routine(t_philo *p)
{
	if (pthread_create(&p->thread_id, NULL, philo_routine, p))
		return (1);
	return (0);
}

int check_meals(t_data *data)
{
	if (data->meals_count == -1)
		return (0);
	t_philo *p = data->first_philo;
	if (p->meals_eaten < data->meals_count)
		return (0);
	if (p->right_philo)
		p = p->right_philo;
	while (p != data->first_philo)
	{
		if (p->meals_eaten < data->meals_count)
			return (0);
		if (p->right_philo)
			p = p->right_philo;
	}
	return (1);
}

t_philo	*check_philo(t_data *data)
{
	t_philo *p = data->first_philo;
	if ((int)(get_current_time() - p->last_meal) >= data->time_to_die)
		return (p);
	if (p->right_philo)
		p = p->right_philo;
	while (p != data->first_philo)
	{
		if ((int)(get_current_time() - p->last_meal) >= data->time_to_die)
			return (p);
		if (p->right_philo)
			p = p->right_philo;
	}
	return (NULL);
}

void Monitor(t_data *data)
{
	if (create_threads(data))
		return ;
	while (!check_philo(data) && !check_meals(data))
	{
		usleep(500);
	}
	if (check_meals(data))
		ft_mutex_write(data->first_philo, "each philosopher is satisfied");
	else
		ft_mutex_write(check_philo(data), "has died of hunger.");
	data->game_over = true;
}

int main(int argc, char *argv[])
{
	t_data		*data;

	data = parse_arguments(argc, argv);
	data = initialize_table(data);

	Monitor(data);

	//printf("%p\n", &data->write_lock);
	//display_table(data);
	free_and_exit(data, NULL);
}
