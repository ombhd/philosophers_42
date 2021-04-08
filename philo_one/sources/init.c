/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:30:56 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/08 12:08:31 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

int		init_philo(t_philo *p, int num_of_philos)
{
	static int i;

	p->num_of_eating = 0;
	p->index = i;
	p->lf_index = i;
	p->rf_index = (i++ + 1) % num_of_philos;
	p->limit = 0;
	return (pthread_mutex_init(&p->pl_mutex, NULL));
}

int		init_data(t_data *data)
{
	unsigned int i;

	if (!(data->philo_trds = (pthread_t *)malloc(
		  sizeof(pthread_t) * data->num_of_philo)) ||
		  !(data->forks = (pthread_mutex_t*)malloc(
			data->num_forks * sizeof(pthread_mutex_t))) ||
		  !(data->philos = (t_philo *)malloc(
		  sizeof(t_philo) * data->num_of_philo)))
	{
		printf("Memory Allocation error\n");
		return (1);
	}
	i = -1;
	while (++i < data->num_of_philo)
	{
		if (init_philo(&data->philos[i], data->num_of_philo) ||
			pthread_mutex_init(&data->forks[i], NULL))
			return (1);
	}
	pthread_mutex_init(&data->mutex_philo, NULL);
	pthread_mutex_init(&data->print_msg, NULL);
	// data->t_start = get_time(0U);
	data->done_eatings = 0;
	data->dead_philo = 0;
	return (0);
}