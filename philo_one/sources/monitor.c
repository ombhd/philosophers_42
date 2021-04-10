/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:54:22 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/10 16:12:28 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void	*dying_checker(void *dt)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)dt;
	data = philo->data;
	while (!philo->done)
	{
		pthread_mutex_lock(&philo->pl_mutex);
		if (get_time(0U) > philo->limit)
		{
			output(philo->index, data, 'd');
			pthread_mutex_unlock(&data->mutex_philo);
			break ;
		}
		pthread_mutex_unlock(&philo->pl_mutex);
		usleep(100);
	}
	return (dt);
}

void	*eating_checker(void *dt)
{
	t_data	*data;

	data = (t_data *)dt;
	if (data->eating_times != -1)
	{
		while (1)
		{
			if (data->done_eatings == data->num_of_philo)
			{
				output(0U, data, 'l');
				pthread_mutex_unlock(&data->mutex_philo);
				return (dt);
			}
		}
	}
	return (dt);
}
