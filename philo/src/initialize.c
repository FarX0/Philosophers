/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initailize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:53:56 by lebartol          #+#    #+#             */
/*   Updated: 2024/07/08 12:57:22 by lebartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*new_philo(t_data *data, int id, t_philo *left_philo);

// Used to allocate philosophers and forks
// i starts from 1 beacause philos id must start from 1
// Crete 1° philo with NULL as left_philosopher beacause is the first
//	=> his left philo will be assigned at the end
// It's used the RIGHT CREATION
//	=> First of all is created first node and assigned to first_philo in data
//		Each time is creted the next one (on his right) and connected
//		with the current one
// In the end, to close the "chain" is conneceted the current node
//	with the first one
t_data	*initialize_table(t_data *data)
{
	t_philo *philo_tmp;
	int		i;

	i = 1;
	philo_tmp = new_philo(data, i++, NULL);
	data->first_philo = philo_tmp;
	while (i <= data->number_of_philosophers)
	{
		philo_tmp->right_philo = new_philo(data, i, philo_tmp);
		philo_tmp->right_philo->left_philo = philo_tmp;
		philo_tmp = philo_tmp->right_philo;
		i++;
	}
	philo_tmp->right_philo = data->first_philo;
	data->first_philo->left_philo = philo_tmp;
	return (data);
}

// Just left node in parameters becuase rigth creation is used
//	=> assign just the left one because you don't know what will be later
static t_philo	*new_philo(t_data *data, int id, t_philo *left_philo)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		free_and_exit(data, "Error\n allocation failed");
	philo->id = id;
	philo->left_philo = left_philo;
	philo->time_to_die = data->time_to_die;
	philo->time_to_eat = data->time_to_eat;
	philo->time_to_sleep = data->time_to_sleep;
	philo->birthday =  data->timestamp;
	philo->last_meal = get_current_time();
	philo->meals_eaten = 0;
	philo->write_lock = data->write_lock;
	return (philo);
}