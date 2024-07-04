/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:05:37 by maceccar          #+#    #+#             */
/*   Updated: 2024/07/04 18:05:37 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	free_philos(t_philo *philo);

// error is used to print an OPTIONAL message error
//	for example during parsing

void		free_and_exit(t_data *data, char *error)
{
	if (error)
		printf("%s\n", error);

	// free_philos(data->philo);

	if (data)
		free(data);
	exit(0);
}

// Pass throw the list of philosophers and free each one
// static void	free_philos(t_philo *philo)
// {
// 	//TO DO da finire, ora è stata fatta just for fan
// 	// per eviare gli errori di compilazione con le flag
// 	if (philo)
// 		free(philo);
// }
