/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:55:14 by lebartol          #+#    #+#             */
/*   Updated: 2024/07/08 15:42:28 by lebartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_mutex_write(t_philo *p, char *str)
{
	while (pthread_mutex_trylock(p->write_lock))
		usleep(100);
	printf("[%zu]\t%d %s\n",(get_current_time() - p->birthday), p->id, str);
	pthread_mutex_unlock(p->write_lock);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	res = 0;
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

long	ft_atol(const char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s == ' ' || (*s > 8 && *s < 14))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
		res = res * 10 + *s++ - '0';
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

t_bool	ft_is_string_numeric(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			if (i == 0)
			{
				if (str[i] != '-' && str[i] != '+')
					return (false);
			}
			else
				return (false);
		}
		i++;
	}
	return (true);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	display_table(t_data *data)
{
	t_philo	*philo_tmp;
	int		i;

	i = 1;
	if (data->number_of_philosophers == 1)
	{
		printf("Current id:%i\n", data->first_philo->id);
		return ;
	}
	philo_tmp = data->first_philo;
	while (i <= data->number_of_philosophers)
	{
		printf("Current id:%i, ", philo_tmp->id);
		printf("on his left id: %i, ", philo_tmp->left_philo->id);
		printf("on his rigth id: %i\n", philo_tmp->right_philo->id);
		philo_tmp = philo_tmp->right_philo;
		i++;
	}
}
