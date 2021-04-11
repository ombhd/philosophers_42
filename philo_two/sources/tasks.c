/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:22:26 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/11 11:31:28 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

void	output(unsigned int index, t_data *data, char task)
{
	unsigned int	time;

	if (sem_wait(data->sem_print) == -1)
		return ;
	time = get_time(data->t_start);
	if (task == 'f')
		printf("%u\t%u has taken a fork\n", time, index + 1);
	else if (task == 'e')
		printf("%u\t%u is eating\n", time, index + 1);
	else if (task == 's')
		printf("%u\t%u is sleeping\n", time, index + 1);
	else if (task == 't')
		printf("%u\t%u is thinking\n", time, index + 1);
	else if (task == 'd')
	{
		printf("%u\t%u died\n", time, index + 1);
		return ;
	}
	else if (task == 'l')
	{
		printf("%u\tEnd of simulation: reached eating limit\n", time);
		return ;
	}
	sem_post(data->sem_print);
}

void	take_forks(t_data *data, t_philo *p)
{
	sem_wait(data->forks);
	output(p->index, data, 'f');
	sem_wait(data->forks);
	output(p->index, data, 'f');
}

void	tasks(t_data *data, t_philo *p)
{
	sem_wait(p->single_pl_sem);
	output(p->index, data, 'e');
	p->limit = get_time(0U) + data->time2die;
	usleep(data->time2eat * 1000);
	++p->num_of_eating;
	sem_post(p->single_pl_sem);
	sem_post(data->forks);
	sem_post(data->forks);
	if (p->num_of_eating != data->eating_times)
	{
		output(p->index, data, 's');
		usleep(data->time2sleep * 1000);
		output(p->index, data, 't');
	}
}
