/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:30:56 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/10 15:20:10 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

int	init_philo(t_philo *p, int num_of_philos)
{
	static int	i;

	p->num_of_eating = 0;
	p->index = i;
	p->lf_index = i;
	p->rf_index = (i++ + 1) % num_of_philos;
	p->limit = 0;
	p->done = 0;
	return (pthread_mutex_init(&p->pl_mutex, NULL));
}

int	alloc_size(void	**ptr, unsigned int len, unsigned int size)
{
	*ptr = malloc(len * size);
	if (!*ptr)
	{
		printf("Memory Allocation error\n");
		return (1);
	}
	return (0);
}

int	init_data(t_data *data)
{
	long int	i;

	i = data->num_of_philo;
	if (alloc_size((void **)&data->philos, i, sizeof(t_philo)) || \
		alloc_size((void **)&data->forks, i, sizeof(pthread_mutex_t)))
		return (1);
	i = -1;
	while (++i < data->num_of_philo)
	{
		if (init_philo(&data->philos[i], data->num_of_philo) || \
			pthread_mutex_init(&data->forks[i], NULL))
			return (1);
	}
	pthread_mutex_init(&data->mutex_philo, NULL);
	pthread_mutex_init(&data->print_msg, NULL);
	data->done_eatings = 0;
	data->dead_philo = 0;
	data->t_start = get_time(0U);
	return (0);
}
