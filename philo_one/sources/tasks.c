/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:22:26 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/07 19:33:20 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void	eating(t_data *data, t_philo *p)
{
	// if (p->is_first_meal)
	// {
	// p->limit = get_time(0U) + data->time2die;
	// 	p->is_first_meal = 0;
	// }
	pthread_mutex_lock(&data->print_msg);
	printf("%u  %u is eating\n", get_time(data->t_start), p->index + 1);
	usleep(data->time2eat * 1000);
	pthread_mutex_unlock(&data->print_msg);
	pthread_mutex_unlock(&data->forks[p->lf_index]);
	pthread_mutex_unlock(&data->forks[p->rf_index]);
	p->num_of_eating++;
}

void	sleeping(t_data *data, t_philo *p)
{
	pthread_mutex_lock(&data->print_msg);
	printf("%u  %u is sleeping\n", get_time(data->t_start), p->index + 1);
	usleep(data->time2sleep * 1000);
	pthread_mutex_unlock(&data->print_msg);
}

void	thinking(t_data *data, t_philo *p)
{
	// pthread_mutex_lock(&p->pl_mutex);
	pthread_mutex_lock(&data->print_msg);
	printf("%u  %u is thinking\n", get_time(data->t_start), p->index + 1);
	pthread_mutex_unlock(&data->print_msg);
	// pthread_mutex_unlock(&p->pl_mutex);
}

void	take_forks(t_data *data, t_philo *p)
{
	pthread_mutex_lock(&data->forks[p->lf_index]);
	printf("%u  %u has taken a fork\n", get_time(data->t_start), p->index + 1);
	pthread_mutex_lock(&data->forks[p->rf_index]);
	printf("%u  %u has taken a fork\n", get_time(data->t_start), p->index + 1);
}
