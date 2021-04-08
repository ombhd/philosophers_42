/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:25:01 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/08 13:28:41 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_one.h"

void	*philo(void *raw_data)
{
	t_data			*data;
	t_philo			*p;
	unsigned int	curr_index;

	data = (t_data *)raw_data;
	curr_index = data->curr_philo;
	p = &data->philos[data->curr_philo];
	// p->is_first_meal = 1;
	p->limit = get_time(0U) + data->time2die;
	pthread_create(&data->dying_checker, NULL, dying_checker, (void *)data);
	pthread_detach(data->dying_checker);
	while (1)
	{
		take_forks(data, p);
		p->limit = get_time(0U) + data->time2die;
		eating(data, p);
		sleeping(data, p);
		thinking(data, p);
	}
	return ((void*)data);
}

int		simulate(t_data *data)
{
	unsigned int i;

	i = 0;
	pthread_create(&data->eating_checker, NULL,eating_checker, (void *)data);
	pthread_detach(data->eating_checker);
	pthread_mutex_lock(&data->mutex_philo);
	data->t_start = get_time(0U);

	while (i < data->num_of_philo)
	{
		data->curr_philo = i;
		pthread_create(&data->philo_trds[i], NULL, philo, (void *)data);
		pthread_detach(data->philo_trds[i]);
		
		usleep(10);
		i++;
	}
	pthread_mutex_lock(&data->mutex_philo);
	pthread_mutex_unlock(&data->mutex_philo);
	return (0);
}

void	print_data(t_data *data)
{
	puts("\n\n======================= DATA ======================\n");

	printf("Num_of_Philos      : %u\n", data->num_of_philo);
	printf("Num_of_Forks       : %u\n", data->num_forks);
	printf("time to eat        : %u\n", data->time2eat);
	printf("time to die        : %u\n", data->time2die);
	printf("time to sleep      : %u\n", data->time2sleep);
	printf("req. eatings times : %d\n", data->eating_times);
	printf("start time         : %u\n\n", data->t_start);

	for (unsigned int i = 0; i < data->num_of_philo; i++)
	{
		printf("Philo |%u|:", i);
		puts("\n--------------------------------");
		printf("\tnum_of_eating: %u\n", data->philos[i].num_of_eating);
		printf("\tindex: %u\n", data->philos[i].index);
		printf("\tlf_index: %u\n", data->philos[i].lf_index);
		printf("\trf_index: %u\n", data->philos[i].rf_index);
		puts("---------------------------------");
	}

	puts("\n===================================================\n");
}

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
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
	// print_data(data);
	// printf("\n======================================================\n\n");
	simulate(data);
	// usleep(5000000);
	// printf("\n======================================================\n");
	return (0);
}