
#ifndef PHILO_H
# define PHILO_H

//Visto che deve essere una "catena" io aggiungerei il prev e il next
//	unendo gli estremi
typedef struct s_philo
{
	//From 1 to number_of_philosophers
	int	id;
}	t_philo;


typedef struct s_data
{
	//Also the number of forks (forchette)
	int	number_of_philosophers;

	//Milisecond
	int	time_to_die;

	//Time it takes for a philosopher to eat (needen two forks)
	int	time_to_eat;

	//Time phoilo will spend sleeping
	int	time_to_sleep;

	//(OPTIONAL) 
	// simulation stops whene all philos have eaten at least
	// n time
	int	number_of_times_each_philosopher_must_eat;

}	t_data;


#endif