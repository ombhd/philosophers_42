/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:54:22 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/07 19:26:22 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"


void	*dying_checker(void *dt)
{
	t_data *data;
	unsigned int i;

	data = (t_data *)dt;
	i = data->curr_philo;
	while (1)
	{
		if (get_time(0U) > data->philos[i].limit)
		{
			pthread_mutex_lock(&data->print_msg);
			printf("%u  %u died\n", get_time(data->t_start), i + 1);
			pthread_mutex_unlock(&data->mutex_philo);
		}
		// usleep(500);
	}
	return (dt);
}


void	*eating_checker(void *dt)
{
	t_data *data;
	unsigned int i;

	data = (t_data *)dt;
	i = 0;
	while (1)
	{
		if (i == data->num_of_philo)
			i = 0;
		if (data->eating_times != -1 && 
			data->philos[i].num_of_eating == data->eating_times)
		{
			data->done_eatings++;
			if (data->done_eatings == data->num_of_philo)
				pthread_mutex_unlock(&data->mutex_philo);
		}
		// usleep(500);
		++i;
	}
	return (dt);
}
