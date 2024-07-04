/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:45:02 by maceccar          #+#    #+#             */
/*   Updated: 2024/07/04 17:45:02 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
	t_data *data;

	data = parse_arguments(argc, argv);

	printf("num: %i\n", data->number_of_philosophers);
	printf("ttdie: %i\n", data->time_to_die);
	printf("tteat: %i\n", data->time_to_eat);
	printf("ttsleep: %i\n", data->time_to_sleep);
	printf("meals count (optional): %i\n", data->meals_count);

	free_and_exit(data, NULL);
}
