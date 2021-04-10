/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:30:56 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/10 19:10:19 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

int	init_philo(t_philo *p, int num_of_philos)
{
	static int	i;

	p->num_of_eating = 0;
	p->index = i;
	p->lf_index = i;
	p->rf_index = (i++ + 1) % num_of_philos;
	p->limit = 0;
	p->done = 0;
	sem_unlink("single_pl_sem");
	p->single_pl_sem = sem_open("single_pl_sem", O_CREAT | O_EXCL, 700, 1);
	if (p->single_pl_sem == SEM_FAILED)
	{
		printf("Creating philosopher semaphore error\n");
		return (1);
	}
	return (0);
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

int	create_semaphores(t_data *data)
{
	sem_unlink("forks");
	data->forks = sem_open("forks", O_CREAT | O_EXCL, 700, data->num_forks);
	if (data->forks == SEM_FAILED)
	{
		printf("Creating forks sempahore error\n");
		return (1);
	}
	sem_unlink("sem_main");
	data->sem_main = sem_open("sem_main", O_CREAT | O_EXCL, 700, 1);
	if (data->sem_main == SEM_FAILED)
	{
		printf("Creating main_sem semaphore error\n");
		return (1);
	}
	sem_unlink("sem_print");
	data->sem_print = sem_open("sem_print", O_CREAT | O_EXCL, 700, 1);
	if (data->sem_print == SEM_FAILED)
	{
		printf("Creating sem_print semaphore error\n");
		return (1);
	}
	return (0);
}

int	init_data(t_data *data)
{
	long int	i;

	i = data->num_of_philo;
	if (alloc_size((void **)&data->philos, i, sizeof(t_philo)) || \
		create_semaphores(data))
		return (1);
	i = -1;
	while (++i < data->num_of_philo)
	{
		if (init_philo(&data->philos[i], data->num_of_philo))
			return (1);
		data->philos[i].data = data;
	}
	data->done_eatings = 0;
	data->t_start = get_time(0U);
	return (0);
}
