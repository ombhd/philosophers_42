/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:54:22 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/12 13:01:18 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	*dying_checker(void *dt)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)dt;
	data = philo->data;
	while (!philo->done)
	{
		sem_wait(philo->single_pl_sem);
		if (get_time(0U) > philo->limit)
		{
			output(philo->index, data, 'd');
			sem_post(data->sem_main);
			break ;
		}
		sem_post(philo->single_pl_sem);
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
			sem_wait(data->sem_eat);
			data->done_eatings++;
			if (data->done_eatings == data->num_of_philo)
			{
				output(0U, data, 'l');
				sem_post(data->sem_main);
				return (dt);
			}
		}
	}
	return (dt);
}
