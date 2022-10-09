/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:40 by frudello          #+#    #+#             */
/*   Updated: 2022/10/04 18:18:56 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

# define TRUE 1
# define FALSE 0

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died"

typedef struct s_config
{
	int			*pid;
	int			id;
	int			num_philo;
	int			num_of_eat;
	long long	last_meal;
	long long	time_sleep;
	long long	time_eat;
	long long	time_die;
	long long	timing;

	sem_t		*die;
	sem_t		*odd;
	sem_t		*write;
	sem_t		*forks;

}t_config;

int			fill_philo_struct(t_config *instance, int lf, int rf, char **argv);
int			fill_struct(t_config *in, int ac, char **av);
int			ft_atoi(const char *str);
int			init_config(int argc, char **argv, t_config *config);
int			create_threads(t_config *instance);
long long	get_time(void);
void		*routine(void *args);
int			join_threads(t_config *instance);
int			philo_eat(t_config *instance, int i);
void		philo_print(t_config *in, char *status);
long long	delta_time(long long time);
void		philo_printo(t_config *in, char *status);
void		check_meal(t_config *in)

int			philo_eat(t_config *instance, int i);
int			philo_sleep(t_config *instance, int i);
void		philo_is_dead(t_config *instance, int i);
int			philo_think(t_config *instance, int i);

int			routine_execute(t_config *instance, int i);
int			drop_forks(t_config *instance, int i);
void		*check(void *args);
void		ft_sleep(t_config *in, long long time);
int			destroy_threads(t_config *instance);
int			check_inputs(int argc, char **argv);
int			ft_isdigit(char *str);
void		ft_free(t_config *instance);
int			check2(t_config *instance, int i);
int			create_threads2(t_config *instance, int i);
#endif