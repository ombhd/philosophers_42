/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:29:30 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/05 19:02:03 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

int		verify_args(t_data *data)
{
	if (data->num_of_philo > 200)
	{
		printf("Invalid philosophers number [valid: <= 200] \n");
		return (1);
	}
	if (data->time2die < 60 || data->time2eat < 60 || data->time2sleep < 60)
	{
		printf("Invalid time argument [valid: >= 60] \n");
		return (1);
	}
	return (0);
}

int		get_args(int ac, char **av, t_data *data)
{
	data->num_of_philo = ft_atoi(av[0]);
	data->num_of_forks = data->num_of_philo;
	data->time2die = ft_atoi(av[1]);
	data->time2eat = ft_atoi(av[2]);
	data->time2sleep = ft_atoi(av[3]);
	if (ac == 5)
		data->eating_times = ft_atoi(av[4]);
	else
		data->eating_times = -1;
	if (verify_args(data))
		return (1);
	return (0);
}