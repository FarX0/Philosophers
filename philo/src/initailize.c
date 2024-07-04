
#include "philo.h"

static t_philo	*new_philo(t_data *data, int id, t_philo *left_philo);

// Used to allocate philosophers and forks
// i starts from 1 beacause philos id must start from 1
// Crete 1° philo with NULL as left_philosopher beacause is the first
t_data	*Initialize_table(t_data *data)
{
	t_philo	*philo_tmp;
	int	i;

	i = 1;
	philo_tmp = new_philo(data, i++, NULL);
	data->first_philo = philo_tmp;
	while (i <= data->number_of_philosophers)
	{
		philo_tmp->right_philo = new_philo(data, i, philo_tmp);
		philo_tmp->right_philo->left_philo = philo_tmp;
		philo_tmp = philo_tmp->right_philo;
		i++;
	}
	philo_tmp->right_philo = data->first_philo;
	data->first_philo->left_philo = philo_tmp;
	return (data);
}

// Just left becuase i use rigth creation
static t_philo	*new_philo(t_data *data, int id, t_philo *left_philo)
{
	t_philo	*philo;
	
	philo = malloc(sizeof(t_philo));
	if (!philo)
		free_and_exit(data, "Error\n allocation failed");
	philo->id = id;
	philo->left_philo = left_philo;
	return (philo);
}