/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:55 by frudello          #+#    #+#             */
/*   Updated: 2022/09/27 16:34:35 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philos(t_config *instance, char **argv)
{
	int	i;
	int	j;

	instance->num_philo = ft_atoi(argv[1]);
	instance->philo = malloc(sizeof(t_philosopher) * instance->num_philo);
	if (instance->philo == NULL)
		return (FALSE);
	i = 0;
	j = 1;
	while (j < instance->num_philo)
	{
		fill_philo_struct(instance, i, j, argv);
		j++;
		i++;
	}
	j = 0;
	fill_philo_struct(instance, i, j, argv);
	return (TRUE);
}

int	create_threads2(t_config *instance, int i)
{
	if (pthread_create(&instance->philo[i].thread, NULL, \
			&routine, (void *) instance) != 0)
		return (FALSE);
		instance->number_of_thread = i;
	usleep(100);
	return (TRUE);
}

int	create_threads(t_config *instance)
{
	int	i;

	i = 0;
	instance->philo_dead = FALSE;
	instance->timing = get_time();
	if (pthread_mutex_init(&instance->write, NULL) != 0)
		return (FALSE);
	usleep(100);
	while (i < instance->num_philo)
	{
		if (!create_threads2(instance, i))
			return (FALSE);
		i++;
	}
	if (pthread_create(&instance->ping, NULL, &check, (void *) instance) != 0)
	{
		destroy_threads(instance);
		return (FALSE);
	}
	usleep(100);
	if (join_threads(instance) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	join_threads(t_config *instance)
{
	int	i;

	i = 0;
	while (i < instance->num_philo)
	{
		if (pthread_join(instance->philo[i].thread, NULL) != 0)
			return (FALSE);
		i++;
		usleep(10);
	}
	if (pthread_join(instance->ping, NULL) != 0)
		return (FALSE);
	return (TRUE);
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
