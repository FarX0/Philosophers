#include "philo.h"

static void	free_philos(t_philo *philo);

// error is used to print an OPTIONAL message error
//	for example during parsing

void		free_and_exit(t_data *data, char *error)
{
	if (error)
		printf("%s\n", error);

	free_philos(data->philo);

	if (data)
		free(data);
	exit(0);
}

// Pass throw the list of philosophers and free each one
static void	free_philos(t_philo *philo)
{
}