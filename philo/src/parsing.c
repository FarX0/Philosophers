
#include "philo.h"

static t_data	*load_arguments(t_data *data, char *argv[], int argc);
static int		get_single_arg(int *taget, char *arg);

// Check argc
// Try and check malloc
// Get the values from argv
t_data	*parse_arguments(int argc, char *argv[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		free_and_exit(data, "Error\n allocation failed\n");
	if (argc != 5 && argc != 6)
		free_and_exit(data, "Error\n wrong number of arguments\n");
	data = load_arguments(data, argv, argc);
	return (data);
}

// Returns data or exit the program bu free_and_free()
// temp is used to store temporary all data to avoid double call
//		of same function with same parameters
static t_data	*load_arguments(t_data *data, char *argv[], int argc)
{
	if (get_single_arg(&data->number_of_philosophers, argv[1]) == -1)
		free_and_exit(data, "Error\n number of philosophers not valid\n");

	if (get_single_arg(&data->time_to_die, argv[2]) == -1)
		free_and_exit(data, "Error\n time to die not valid\n");

	if (get_single_arg(&data->time_to_eat, argv[3]) == -1)
		free_and_exit(data, "Error\n time to eat not valid\n");

	if (get_single_arg(&data->time_to_sleep, argv[4]) == -1)
		free_and_exit(data, "Error\n time to live not valid\n");	

	if (argc == 6)
	{
		if (get_single_arg(&data->number_of_times_each_philosopher_must_eat, argv[5]) == -1)
			free_and_exit(data, "Error\n number of eating not valid\n");	
	}
	else	
		data->number_of_times_each_philosopher_must_eat = -1;

	return (data);
}

// Used to check every single argc because all of them respect the same
//	rules and are of the same type
// Assign to target the value get by arg
// Return the number alreay parsed or -1 if ther's some errors
static int	get_single_arg(int *taget, char *arg)
{
	if (ft_atol(arg) < INT_MIN || ft_atol(arg) > INT_MAX )
		return (-1);
	*taget = ft_atoi(arg);
	return (*taget);
}