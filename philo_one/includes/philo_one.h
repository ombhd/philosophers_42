/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:24:41 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/05 18:35:43 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
#define PHILO_ONE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef	struct	s_philo
{
	unsigned int 	num_of_eating;
	unsigned int 	index;
	unsigned int 	lf_index;
	unsigned int 	rf_index;
	pthread_mutex_t pl_mutex;
	
}				t_philo;

typedef struct	s_data
{
	unsigned int	num_of_philo;
	unsigned int	num_of_forks;
	unsigned int	time2die;
	unsigned int	time2eat;
	unsigned int	time2sleep;
	int 			eating_times;
	
	pthread_mutex_t	*forks;
	pthread_mutex_t	eating;
	pthread_mutex_t	print_msg;
	// pthread_mutex_lock(&forks[philo->lf_index])
	t_philo			*philos;
	pthread_t		*philo_trds;
}				t_data;

int			ft_atoi(const char *);
int			get_args(int, char **, t_data *);
int			verify_args(t_data *);
int			init_data(t_data *);

#endif // !PHILO_ONE_H