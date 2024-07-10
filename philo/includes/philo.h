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
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				id;
	int				meals_eaten;
	size_t			last_meal;
	size_t			birthday;

	struct s_philo	*right_philo;
	struct s_philo	*left_philo;

	pthread_t		thread_id;
	pthread_mutex_t *write_lock;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

// All usigned because they can't be negative
typedef struct s_data
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals_count;
	size_t	timestamp;
	t_philo	*first_philo;
	pthread_mutex_t *write_lock;
}	t_data;

t_data	*parse_arguments(int argc, char *argv[]);

t_data	*initialize_table(t_data *data);

void	display_table(t_data *data);

void	free_and_exit(t_data *data, char *error);

int		create_philo_routine(t_philo *p);

void	ft_mutex_write(t_philo *p, char *str);

void	philo_sleep(t_philo *p);

void philo_eat(t_philo *p);

#endif
