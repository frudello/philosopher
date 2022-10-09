/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:55 by frudello          #+#    #+#             */
/*   Updated: 2022/10/04 18:12:51 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fill_struct(t_config *in, int ac, char **av)
{
	in->num_philo = ft_atoi(av[1]);
	in->time_die = ft_atoi(av[2]);
	in->time_eat = ft_atoi(av[3]);
	in->time_sleep = ft_atoi(av[4]);
	in->timing = get_time();
	in->last_meal = in->timing;
	if (ac == 6)
		in->num_of_eat = ft_atoi(av[5]);
	else
		in->num_of_eat = -1;
	sem_unlink("sem_die");
	sem_unlink("sem_fork");
	sem_unlink("sem_write");
	sem_unlink("sem_odd");
	in->die = sem_open("sem_die", O_CREAT, 0644, 0);
	in->odd = sem_open("sem_odd", O_CREAT, 0644, 1);
	in->forks = sem_open("sem_fork", O_CREAT, 0644, in->num_philo);
	in->write = sem_open("sem_write", O_CREAT, 0644, 1);
	init_proces(in);
	return (TRUE);
}

void	init_proces(t_config *in)
{
	int	i;

	i = 0;
	in->pid = (int *)malloc (sizeof(int) * in->num_philo);
	while (i < in->num_philo)
	{
		if (i == 0 || in->pid[i - 1] != 0)
		{
			in->pid = fork();
			if (in->pid[i] == 0)
			{
				in->id = i + 1;
				ft_child_set(in);
			}
		}
		i++;
	}
}

void	ft_child_set(t_config *in)
{
	check_die(in);
	sem_wait(in->forks);
	philo_print(in, FORK);
	if ((ft_get_time() - in->last_meal) + in->time_eat >= in->time_die && in->num_philo % 2 == 1)
		ft_usleep((arg, ft_get_time() - arg->time_left) + arg->time_eat + 1);
	if (in->num_philo == 1)
		ft_usleep(in->time_die + 1);
	sem_wait(in->forks);
	philo_print(in, FORK);
	sem_post(in->odd);
	in->last_meal = ft_get_time();
	philo_print(in, EAT);
	ft_usleep(in->time_eat);
	sem_post(in->forks);
	sem_post(in->forks);
	check_meal(in);
	philo_print(in, SLEEP);
	ft_usleep(in, in->time_sleep);
	philo_print(in, THINK);
}

void	check_die(t_config *in)
{
	if (delta_time(in->last_meal) >= in->time_die)
	{
		philo_printo(in, DIED);
		sem_wait(in->write);
		sem_wait(in->die);
		free(in->pid);
		exit (1);
	}
}

int	destroy_threads(t_config *instance)
{
	int	i;

	i = 0;
	while (i < instance->num_philo)
	{
		pthread_mutex_destroy(&instance->forks[i]);
		i++;
		usleep(100);
	}
	pthread_mutex_destroy(&instance->write);
	return (TRUE);
}
