/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:05:01 by lebartol          #+#    #+#             */
/*   Updated: 2024/07/17 18:47:00 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void philo_sleep(t_philo *p)
{
	ft_mutex_write(p, "is sleeping.");
	ft_usleep(p->data->time_to_sleep);
}

void philo_eat(t_philo *p)
{
	pthread_mutex_lock(&p->r_fork);
	pthread_mutex_lock(p->l_fork);
	ft_mutex_write(p, "took right fork.");
	ft_mutex_write(p, "took left fork.");
	ft_mutex_write(p, "is eating.");
	p->last_meal = get_current_time(); //da sistemare data corsa
	p->meals_eaten++;
	printf("%d has eaten %d\n", p->id, p->meals_eaten);
	if (p->meals_eaten == p->to_eat)
		check_food(p->data, p->id, 1);
	ft_usleep(p->data->time_to_eat);
	pthread_mutex_unlock(p->l_fork);
	pthread_mutex_unlock(&p->r_fork);
}
