/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:24:41 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/07 18:55:00 by obouykou         ###   ########.fr       */
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
	int 			num_of_eating;
	unsigned int 	index;
	unsigned int 	lf_index;
	unsigned int 	rf_index;
	unsigned int 	limit;
	char			is_first_meal;
	pthread_mutex_t pl_mutex;
	
}				t_philo;

typedef struct	s_data
{
	unsigned int	num_of_philo;
	unsigned int	num_forks;
	unsigned int	time2die;
	unsigned int	time2eat;
	unsigned int	time2sleep;
	int 			eating_times;
	unsigned int	done_eatings;
	char			dead_philo;
	unsigned int 	t_start;
	unsigned int 	curr_philo;
	
	pthread_mutex_t	*forks;
	pthread_t		eating_checker;
	pthread_t		dying_checker;
	pthread_mutex_t	mutex_philo;
	pthread_mutex_t	print_msg;
	t_philo			*philos;
	pthread_t		*philo_trds;
}				t_data;

int				ft_atoi(const char *);
int				get_args(int, char **, t_data *);
int				verify_args(t_data *);
int				init_data(t_data *);
unsigned int 	get_time(unsigned int);
void			take_forks(t_data *, t_philo *);
void			eating(t_data *, t_philo *);
void			sleeping(t_data *, t_philo *);
void			thinking(t_data *, t_philo *);
void			*dying_checker(void *);
void			*eating_checker(void *);




#endif // !PHILO_ONE_H

/**
 * 	- thread monitor get_time() > limit => lock output | g_die = 0
 * 	
 * limit = get_time() + time_to_die
 * 
 * lock fork
 * 	print fork
 * lock fork
 * 	print fork
 * 		limit = get_time() + time_to_die
 * print is eating
 * 
 * 	sleep
 * unlock fork
 * unlock fork
 * print sleeping
 * start sleeping
 * print thinking
 * */