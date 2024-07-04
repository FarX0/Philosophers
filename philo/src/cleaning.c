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
// TO DO rifarlo meglio pls
static void	free_philos(t_data *data)
{
	t_philo	*philo_tmp;
	int		i;

	if (!data->first_philo)
		return ;
	i = 1;
	philo_tmp = data->first_philo;
	while (i < data->number_of_philosophers)
	{
		 t_philo *next_philo = philo_tmp->right_philo; // Save the next philo before freeing
        free(philo_tmp->left_philo);
        philo_tmp = next_philo; // Move to the next philo
		i++;
	}
	free(data->first_philo);
}
