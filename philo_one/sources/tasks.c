/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:22:26 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/08 13:13:24 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void	output(unsigned int index, t_data *data)
{
	char task;

	task = data->philos[index].task;
	if (pthread_mutex_lock(&data->print_msg))
		return ;
	if (task == 'e')
		printf("%u  %u is eating\n", get_time(data->t_start), index + 1);
	else if (task == 's')
		printf("%u  %u is sleeping\n", get_time(data->t_start), index + 1);
	else if (task == 't')
		printf("%u  %u is thinking\n", get_time(data->t_start), index + 1);
	else if (task == 'l')
		printf("%u  %u has taken a fork\n", get_time(data->t_start), index + 1);
	else if (task == 'r')
		printf("%u  %u has taken a fork\n", get_time(data->t_start), index + 1);
	pthread_mutex_unlock(&data->print_msg);
}

void	eating(t_data *data, t_philo *p)
{
	p->task = 'e';
	output(p->index, data);
	usleep(data->time2eat * 1000);
	pthread_mutex_unlock(&data->forks[p->lf_index]);
	pthread_mutex_unlock(&data->forks[p->rf_index]);
	p->num_of_eating++;
}

void	sleeping(t_data *data, t_philo *p)
{
	p->task = 's';
	output(p->index, data);
	usleep(data->time2sleep * 1000);
}

void	thinking(t_data *data, t_philo *p)
{
	p->task = 't';
	output(p->index, data);
}

void	take_forks(t_data *data, t_philo *p)
{
	p->task = 'l';
	pthread_mutex_lock(&data->forks[p->lf_index]);
	output(p->index, data);
	p->task = 'r';
	pthread_mutex_lock(&data->forks[p->rf_index]);
	output(p->index, data);
}
