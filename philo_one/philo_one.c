/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:25:01 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/05 19:07:22 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_one.h"

void *test_func(void *a)
{
	printf("hello ==> |%d|\n", *((int *)a));
	sleep(2);
	printf("see ya ==> |%d|\n", *((int *)a));
	void *v = NULL;
	return v;
}

void	eating(t_data *data, t_philo *p)
{
	pthread_mutex_lock(&data->print_msg);
	printf("time %d is eating", p->index + 1);
	usleep(data->time2eat * 1000);
	pthread_mutex_lock(&data->print_msg);
}

void	sleeping(t_data *data, t_philo *p)
{
	pthread_mutex_lock(&data->print_msg);
	printf("time %d is sleeping", p->index + 1);
	usleep(data->time2sleep * 1000);
	pthread_mutex_lock(&data->print_msg);
}

void	thinking(t_data *data, t_philo *p)
{
	pthread_mutex_lock(&data->print_msg);
	printf("time %d is thinking", p->index + 1);
	pthread_mutex_lock(&data->print_msg);
}

int		simulate(t_data *data)
{
	unsigned int i;

	i = -1;
	while (1)
	{
		
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac != 4 && ac != 5)
	{
		printf("USAGE: ./philo_one  number_of_philosophers  time_to_die");
		printf("  time_to_eat time_to_sleep");
		printf("  [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (!(data = (t_data *)malloc(sizeof(t_data))))
	{
		printf("Memory allocation error\n");
		return (1);
	}
	if (get_args(ac, av, data) || init_data(data))
		return (1);
	simulate(data);
	return (0);
	
	
	// struct timeval *tmvl;
	// pthread_mutex_init(&mutex_lock, NULL);

	// pthread_create(&p, NULL, say_1, (void *)p);
	// pthread_create(&p, NULL, say_2, (void *)p);
	// pthread_detach(p);
	// pthread_mutex_lock(&mutex_lock);
}