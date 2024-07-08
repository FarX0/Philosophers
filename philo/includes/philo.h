/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:01:24 by lebartol          #+#    #+#             */
/*   Updated: 2024/07/08 15:41:17 by lebartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include "utils.h"

// Is managed as a "chain" connecting first and last "nodes"
typedef struct s_philo
{
	//From 1 to number_of_philosophers
	int				id;
	int				meals_eaten;
	int				last_meal;

	struct s_philo	*right_philo;
	struct s_philo	*left_philo;
	pthread_mutex_t	is_dead;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	l_fork;
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

	// Thi philo is that one with id=1
	t_philo	*first_philo;

	pthread_t *thread_id;

}	t_data;

t_data	*parse_arguments(int argc, char *argv[]);

t_data	*initialize_table(t_data *data);

void	display_table(t_data *data);

void	free_and_exit(t_data *data, char *error);

#endif
