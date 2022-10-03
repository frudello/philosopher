/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:25 by frudello          #+#    #+#             */
/*   Updated: 2022/10/03 13:35:52 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_config *in, int i)
{
	if (pthread_mutex_lock(&in->forks[in->philo[i].fork_left]) != 0)
		return (FALSE);
	if (philo_print(in, in->philo[i].id, FORK_LEFT) == FALSE)
		return (FALSE);
	if (pthread_mutex_lock(&in->forks[in->philo[i].fork_right]) != 0)
		return (FALSE);
	if (philo_print(in, in->philo[i].id, FORK_RIGHT) == FALSE)
		return (FALSE);
	if (philo_print(in, in->philo[i].id, EAT) == FALSE)
		return (FALSE);
	in->philo[i].last_meal = get_time();
	ft_sleep(in->philo[i].time_to_eat);
	drop_forks(in, i);
	return (TRUE);
}

int	philo_sleep(t_config *instance, int i)
{
	if (philo_print(instance, i, SLEEP) == FALSE)
		return (FALSE);
	ft_sleep(instance->philo[i].time_to_sleep);
	return (TRUE);
}

int	philo_think(t_config *instance, int i)
{
	if (philo_print(instance, instance->philo[i].id, THINK) == FALSE)
		return (FALSE);
	return (TRUE);
}

void	philo_is_dead(t_config *instance, int i)
{
	long long	time;

	time = delta_time(instance->philo[i].last_meal);
	if (time >= instance->input_time_to_die)
	{
		destroy_threads(instance);
		philo_print(instance, instance->philo[i].id, DIED);
		instance->philo_dead = TRUE;
		exit(0);
	}
}

int	drop_forks(t_config *in, int i)
{
	if (pthread_mutex_unlock(&in->forks[in->philo[i].fork_left]) != 0)
		return (FALSE);
	if (pthread_mutex_unlock(&in->forks[in->philo[i].fork_right]) != 0)
		return (FALSE);
	in->philo[i].num_of_times_ate++;
	return (TRUE);
}
