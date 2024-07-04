
#include "philo.h"

int main(int argc, char *argv[])
{
	t_data *data;

	data = parse_arguments(argc, argv);

	printf("num: %i\n", data->number_of_philosophers);
	printf("ttdie: %i\n", data->time_to_die);
	printf("tteat: %i\n", data->time_to_eat);
	printf("ttsleep: %i\n", data->time_to_sleep);
	printf("num_eating_time (optional): %i\n", data->number_of_times_each_philosopher_must_eat);

	free_and_exit(data, NULL);
}