/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:01:24 by maceccar          #+#    #+#             */
/*   Updated: 2024/07/04 18:01:24 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "utils.h"

//Visto che deve essere una "catena" io aggiungerei il prev e il next
//	unendo gli estremi
typedef struct s_philo
{
	//From 1 to number_of_philosophers
	int	id;
}	t_philo;


// All usigned because they can't be negative
typedef struct s_data
{
	//Also the number of forks (forchette)
	int		number_of_philosophers;

	//Milisecond
	int		time_to_die;

	//Time it takes for a philosopher to eat (needen two forks)
	int		time_to_eat;

	//Time phoilo will spend sleeping
	int		time_to_sleep;

	//(OPTIONAL) 
	// simulation stops whene all philos have eaten at least
	// n time
	// if not defined: -1
	int		meals_count;

	t_philo	*philo;

}	t_data;

t_data	*parse_arguments(int argc, char *argv[]);

void	free_and_exit(t_data *data, char *error);

int	ft_isdigit(int c);

#endif
