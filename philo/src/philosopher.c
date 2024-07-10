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

void fetch_forks(t_philo *p)
{
	
}

void philo_sleep(t_philo *p)
{
	ft_mutex_write(p, "is sleeping soundly.");
	ft_usleep(p->time_to_sleep);
}

void philo_eat(t_philo *p)
{
	fetch_forks(p);
}
