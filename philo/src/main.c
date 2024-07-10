/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:45:02 by lebartol          #+#    #+#             */
/*   Updated: 2024/07/08 15:37:47 by lebartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	if (philo->id % 2)
		philo_sleep(philo);
	while (1)
	{
		philo_eat();
		philo_sleep();
	}
	return (NULL);
}

//TO DO spostare questa cosa direttamente in initialize_table()
int create_threads(t_data *data)
{
	t_philo *p = data->first_philo;
	if (create_philo_routine(p))
		return (1);
	p = p->right_philo;
	while (p != data->first_philo)
	{
		if (create_philo_routine(p))
			return (1);
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



t_philo	*check_philo(t_data *data)
{
	t_philo *p = data->first_philo;
	if ((int)(get_current_time() - p->last_meal) > data->time_to_die)
		return (p);
	if (p->right_philo)
		p = p->right_philo;
	while (p != data->first_philo)
	{
		if ((int)(get_current_time() - p->last_meal) > data->time_to_die)
			return (p);
		if (p->right_philo)
			p = p->right_philo;
	}
	return (NULL);
}

void Monitor(t_data *data)
{
	// t_data *data = (t_data *)vargp;

	if (create_threads(data))
		return;
	while (!check_philo(data))
	{
		usleep(100);
	}
	ft_mutex_write(check_philo(data), "has died of hunger.\n");
	free_and_exit(data, NULL);
	//pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	t_data		*data;
	pthread_mutex_t printing;


	if (pthread_mutex_init(&printing, NULL) != 0)
		return (0);
	data = parse_arguments(argc, argv);
	data->write_lock = &printing;
	data = initialize_table(data);

	Monitor(data);

	//display_table(data);

}
