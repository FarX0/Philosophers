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

static void	free_philos(t_data *data);

// error is used to print an OPTIONAL message error
//	for example during parsing

void	free_and_exit(t_data *data, char *error)
{
	if (error)
		printf("%s\n", error);
	free_philos(data);
	if (data)
		free(data);
	exit(0);
}

// Pass throw the list of philosophers and free each one
// Check if first_philo is null, in this case there would have been
//	an error during parsing
static void	free_philos(t_data *data)
{
	t_philo	*philo_tmp;
	int		i;

	i = 0;
	if (!data->first_philo)
		return ;
	philo_tmp = data->first_philo;
	while (i < data->number_of_philosophers)
	{
		data->first_philo = philo_tmp->right_philo;
		free(philo_tmp);
		philo_tmp = data->first_philo;
		i++;
	}
	data->first_philo = NULL;
}
