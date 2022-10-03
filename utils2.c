/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:58 by frudello          #+#    #+#             */
/*   Updated: 2022/09/27 15:52:58 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fill_philo_struct(t_config *instance, int lf, int rf, char **argv)
{
	instance->philo[lf].id = lf;
	instance->philo[lf].num_of_times_ate = 0;
	instance->philo[lf].fork_left = lf;
	instance->philo[lf].fork_right = rf;
	instance->input_time_to_die = ft_atoi(argv[2]);
	instance->philo[lf].time_to_eat = ft_atoi(argv[3]);
	instance->philo[lf].time_to_sleep = ft_atoi(argv[4]);
	instance->num_of_times_eat = -1;
	if (argv[5])
		instance->num_of_times_eat = ft_atoi(argv[5]);
	return (TRUE);
}

int	ft_atoi(const char *str)
{
	size_t	c;
	int		s;
	int		res;

	c = 0;
	s = 1;
	res = 0;
	while ((str[c] >= 9 && str[c] <= 13) || str[c] == 32)
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			s *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = (str[c] - '0') + (res * 10);
		c++;
	}
	return (res * s);
}

long long	delta_time(long long time)
{
	if (time > 0)
		return (get_time() - time);
	return (0);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (uint64_t)1000) + (time.tv_usec / (uint64_t)1000));
}

int	philo_print(t_config *instance, int id, char *status)
{
	long long	now;

	now = delta_time(instance->timing);
	if (instance->philo_dead == TRUE)
		return (FALSE);
	pthread_mutex_lock(&instance->write);
	if (instance->philo_dead == TRUE)
	{
		pthread_mutex_unlock(&instance->write);
		return (FALSE);
	}
	else
		printf("%lld %d %s\n", now, id + 1, status);
	pthread_mutex_unlock(&instance->write);
	return (TRUE);
}
