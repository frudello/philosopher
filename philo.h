/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:40 by frudello          #+#    #+#             */
/*   Updated: 2022/10/03 13:34:04 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK_LEFT "has taken a left fork"
# define FORK_RIGHT "has taken a right fork"
# define DIED "died"

typedef struct s_philosopher
{
	pthread_t	thread;

	int			id;
	int			fork_left;
	int			fork_right;
	int			num_of_times_ate;

	long long	time_to_eat;
	long long	time_to_sleep;
	long long	last_meal;

}					t_philosopher;

typedef struct s_config
{
	int				number_of_thread;
	int				num_philo;
	int				num_of_times_eat;
	long long		input_time_to_die;
	int				philo_dead;
	long long		timing;

	pthread_t		ping;
	t_philosopher	*philo;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;

}t_config;

int			one_philo(t_config *in, int i);
int			fill_philo_struct(t_config *instance, int lf, int rf, char **argv);
int			create_philos(t_config *instance, char **argv);
int			ft_atoi(const char *str);
int			init_config(int argc, char **argv, t_config *config);
int			create_threads(t_config *instance);
int			create_forks(t_config *instance);
long long	get_time(void);
void		*routine(void *args);
int			join_threads(t_config *instance);
int			philo_eat(t_config *instance, int i);
int			philo_print(t_config *instance, int id, char *status);
long long	delta_time(long long time);

int			philo_eat(t_config *instance, int i);
int			philo_sleep(t_config *instance, int i);
void		philo_is_dead(t_config *instance, int i);
int			philo_think(t_config *instance, int i);

int			routine_execute(t_config *instance, int i);
int			drop_forks(t_config *instance, int i);
void		*check(void *args);
void		ft_sleep(long long time);
int			destroy_threads(t_config *instance);
int			check_inputs(int argc, char **argv);
int			ft_isdigit(char *str);
void		ft_free(t_config *instance);
int			check2(t_config *instance, int i);
int			create_threads2(t_config *instance, int i);
#endif