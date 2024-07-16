/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:55:14 by lebartol          #+#    #+#             */
/*   Updated: 2024/07/08 15:42:28 by lebartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_mutex_write(t_philo *p, char *str)
{
	while (pthread_mutex_trylock(&p->data->write_lock))
		usleep(100);
	if (p->data->game_over)
	{
		pthread_mutex_unlock(&p->data->write_lock);
		return ;
	}
	printf("[%zu]\t%d\t%s\n",(get_current_time() - p->birthday), p->id, str);
	pthread_mutex_unlock(&p->data->write_lock);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	res = 0;
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

long	ft_atol(const char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s == ' ' || (*s > 8 && *s < 14))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
		res = res * 10 + *s++ - '0';
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

t_bool	ft_is_string_numeric(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			if (i == 0)
			{
				if (str[i] != '-' && str[i] != '+')
					return (false);
			}
			else
				return (false);
		}
		i++;
	}
	return (true);
}

// TO DO in caso di errore nel gettimeofday non sarebbe meglio uscire direttamente con la funzione
// free_adn_exit()? so che non succede mai ma se dovesse succedere si sfanculerebbe tutto??
size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

//TO DO avevi messo 500 ma ho visto che molti usano 1000 
int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(1000)
	return (0);
}

//start from 1 and and at num of philo just to follow id order
void	display_table(t_data *data)
{
	t_philo	*philo_tmp;
	int		i;

	i = 1;
	// if (data->number_of_philosophers == 1)
	// {
	// 	printf("Current id:%i\n", data->first_philo->id);
	// }
	printf("%p writelock\n", &data->write_lock);
	printf("%p gameover\n", &data->game_over);
	philo_tmp = data->first_philo;
	while (i <= data->number_of_philosophers)
	{
		printf("%p <- Current id:%i -> %p\n", philo_tmp->l_fork, philo_tmp->id, &philo_tmp->r_fork);
		printf("on his left id: %p, ", &philo_tmp->left_philo->id);
		printf("on his rigth id: %p\n", &philo_tmp->right_philo->id);
		philo_tmp = philo_tmp->right_philo;
		i++;
	}
}
