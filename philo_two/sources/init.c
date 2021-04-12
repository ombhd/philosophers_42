/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:30:56 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/12 13:02:44 by obouykou         ###   ########.fr       */
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

int	create_semaphore(const char *name, int value, sem_t **semaphore)
{
	sem_unlink(name);
	*semaphore = sem_open(name, O_CREAT | O_EXCL, 700, value);
	if (*semaphore == SEM_FAILED)
	{
		printf("Creating %s semaphore error\n", name);
		return (1);
	}
	return (0);
}

int	create_semaphores(t_data *data)
{
	if (create_semaphore("forks", data->num_forks, &data->forks))
		return (1);
	if (create_semaphore("sem_main", 1, &data->sem_main))
		return (1);
	if (create_semaphore("sem_print", 1, &data->sem_print))
		return (1);
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
