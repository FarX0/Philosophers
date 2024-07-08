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

int	dead_philo(t_philo *p, t_data *d)
{
	if (!p)
		return (0);
	int	first_id;
	first_id = p->id;
	if (p->last_meal > d->time_to_die)
		return (1);
	p = p->right_philo;
	while (p->id != first_id)
	{
		if (p->last_meal > d->time_to_die)
			return (1);
		p = p->right_philo;
	}
	return (0);
}

void *Monitor(void *vargp)
{
	t_data *data = (t_data *)vargp;

	while (!dead_philo(data->first_philo, data))
	{
		ft_usleep(1000);
	}
	return (NULL);
}

int main(int argc, char *argv[])
{
	t_data *data;

	data = parse_arguments(argc, argv);
	data = initialize_table(data);

	display_table(data);
	pthread_create(data->thread_id, NULL, Monitor, data);


	free_and_exit(data, NULL);
}
