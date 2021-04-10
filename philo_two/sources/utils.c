/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:29:30 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/10 16:04:23 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

int	verify_args(t_data *data)
{
	if (data->num_of_philo > 200 || data->num_of_philo < 2)
	{
		printf("Invalid philosophers number [ 2 <= valid_number <= 200] \n");
		return (1);
	}
	if (data->time2die < 60 || data->time2eat < 60 || data->time2sleep < 60)
	{
		printf("Invalid time argument [valid: >= 60] \n");
		return (1);
	}
	if (data->ac == 6 && data->eating_times <= 0)
	{
		printf("Invalid times of eating [ 0 < valid_number] \n");
		return (1);
	}
	return (0);
}

int	get_args(int ac, char **av, t_data *data)
{
	data->num_of_philo = ft_atoi(av[1]);
	data->num_forks = data->num_of_philo;
	data->time2die = ft_atoi(av[2]);
	data->time2eat = ft_atoi(av[3]);
	data->time2sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->eating_times = ft_atoi(av[5]);
	else
		data->eating_times = -1;
	data->ac = ac;
	if (verify_args(data))
		return (1);
	return (0);
}

unsigned int	get_time(unsigned int start)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return (((1000 * tm.tv_sec) + (tm.tv_usec / 1000)) - start);
}

void	clean(t_data *data)
{
	while (data->num_forks--)
	{
		pthread_mutex_destroy(&data->forks[data->num_forks]);
		pthread_mutex_destroy(&data->philos[data->num_forks].pl_mutex);
	}
	free(data->forks);
	free(data->philos);
	pthread_mutex_destroy(&data->mutex_philo);
	pthread_mutex_destroy(&data->print_msg);
	free(data);
}
