/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:48 by frudello          #+#    #+#             */
/*   Updated: 2022/10/03 13:34:34 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_config	*instance;
	int			i;

	instance = (t_config *)args;
	i = instance->number_of_thread;
	instance->philo[i].last_meal = get_time();
	if (instance->num_of_times_eat > 0)
	{
		while (instance->num_of_times_eat > instance->philo[i].num_of_times_ate \
				&& instance->philo_dead == FALSE)
		{
			if (routine_execute(instance, i) == FALSE)
				break ;
		}
	}
	else
	{
		while (instance->philo_dead == FALSE)
		{
			if (routine_execute(instance, i) == FALSE)
				break ;
		}
	}
	return (NULL);
}

int	routine_execute(t_config *instance, int i)
{
	if (philo_eat(instance, i) == FALSE)
		return (FALSE);
	if (instance->num_of_times_eat != instance->philo[i].num_of_times_ate)
	{
		if (philo_sleep(instance, i) == FALSE)
			return (FALSE);
		if (philo_think(instance, i) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

int	check2(t_config *instance, int i)
{	
	while (instance->philo_dead == FALSE)
		philo_is_dead(instance, i);
	return (1);
}

void	*check(void *args)
{
	t_config	*instance;
	static int	i;

	instance = (t_config *)args;
	if (i >= instance->num_philo)
		i = 0;
	if (instance->num_of_times_eat > 0)
	{
		while (instance->num_of_times_eat > instance->philo[i].num_of_times_ate \
				&& instance->philo_dead == FALSE)
			philo_is_dead(instance, i);
	}
	else
		check2 (instance, i);
	i += 1;
	return (NULL);
}
