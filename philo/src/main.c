/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:45:02 by lebartol          #+#    #+#             */
/*   Updated: 2024/07/17 18:47:29 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	if (philo->id % 2)
		philo_sleep(philo);
	printf("%d has to eat %d times\n", philo->id, philo->to_eat);
	while (!get_gameover(philo->data, false))
	{
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}

//TODO spostare questa cosa direttamente in initialize_table()
int create_threads(t_data *data)
{
	t_philo *p;
	
	p = data->first_philo;
	if (create_philo_routine(p))
	{
		return (1);
	}
	p = p->right_philo;
	while (p != data->first_philo)
	{
		if (create_philo_routine(p))
		{
			return (1);
		}
		p = p->right_philo;
	}
	return (0);
}

int create_philo_routine(t_philo *p)
{
	if (pthread_create(&p->thread_id, NULL, philo_routine, p))
		return (1);
	return (0);
}

int main(int argc, char *argv[])
{
	t_data		*data;

	data = parse_arguments(argc, argv);
	data = initialize_table(data);

	Monitor(data);

	//display_table(data);
	free_and_exit(data, NULL);
}
