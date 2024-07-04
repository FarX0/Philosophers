/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:55:57 by maceccar          #+#    #+#             */
/*   Updated: 2024/07/04 17:55:57 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

int		ft_atoi(const char *str);

long	ft_atol(const char *s);

t_bool	ft_is_string_numeric(const char *str);

int		ft_isdigit(int c);

#endif
