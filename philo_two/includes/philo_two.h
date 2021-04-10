/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:24:41 by obouykou          #+#    #+#             */
/*   Updated: 2021/04/10 18:55:12 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct s_philo
{
	unsigned int	index;
	unsigned int	lf_index;
	unsigned int	rf_index;
	unsigned int	limit;
	int				num_of_eating;
	char			done;
	char			*name;
	sem_t			*single_pl_sem;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	long int		num_of_philo;
	long int		num_forks;
	long int		time2die;
	long int		time2eat;
	long int		time2sleep;
	long int		eating_times;
	unsigned int	done_eatings;
	unsigned int	t_start;
	unsigned int	ac;
	sem_t			*forks;
	sem_t			*sem_main;
	sem_t			*sem_print;
	pthread_t		eating_checker;
	pthread_t		dying_checker;
	t_philo			*philos;
}				t_data;

long int		ft_atoi(const char *str);
int				get_args(int ac, char **av, t_data *data);
int				verify_args(t_data *data);
int				init_data(t_data *data);
unsigned int	get_time(unsigned int start);
void			take_forks(t_data *data, t_philo *philo);
void			tasks(t_data *data, t_philo *philo);
void			output(unsigned int index, t_data *data, char task);
void			*dying_checker(void *dt);
void			*eating_checker(void *dt);
void			clean(t_data *data);

#endif // !PHILO_TWO_H
