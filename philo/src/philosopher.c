/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:05:01 by lebartol          #+#    #+#             */
/*   Updated: 2024/07/08 12:57:22 by lebartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void philo_sleep(t_philo *p)
{
	ft_mutex_write(p, "is sleeping.");
	ft_usleep(p->time_to_sleep);
}

void philo_eat(t_philo *p)
{
	while (pthread_mutex_trylock(&p->r_fork))
		usleep(100);
	ft_mutex_write(p, "took right fork.");
	while (pthread_mutex_trylock(p->l_fork))
		usleep(100);
	ft_mutex_write(p, "took left fork.");
	ft_mutex_write(p, "is eating.");
	p->last_meal = get_current_time();
	p->meals_eaten++;
	ft_usleep(p->time_to_eat);
	pthread_mutex_unlock(&p->r_fork);
	pthread_mutex_unlock(p->l_fork);
}
