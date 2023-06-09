/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:56:29 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/10 16:41:58 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_is_exit(t_data *data)
{
	bool	exit;

	pthread_mutex_lock(&data->mtx_exit);
	exit = data->exit;
	pthread_mutex_unlock(&data->mtx_exit);
	return (exit);
}

void	ft_set_exit(t_data *data)
{
	pthread_mutex_lock(&data->mtx_exit);
	data->exit = true;
	pthread_mutex_unlock(&data->mtx_exit);
}

bool	ft_set_time_last_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->mtx_time_last_eaten);
	philo->time_last_eaten = ft_get_time(0);
	pthread_mutex_unlock(&philo->mtx_time_last_eaten);
	return (RETURN_SUCCESS);
}

bool	ft_increment_eat_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->mtx_eat_count);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mtx_eat_count);
	return (RETURN_SUCCESS);
}

int	ft_get_eat_count(t_philo *philo)
{
	int	eat_count;

	pthread_mutex_lock(&philo->mtx_eat_count);
	eat_count = philo->eat_count;
	pthread_mutex_unlock(&philo->mtx_eat_count);
	return (eat_count);
}
