/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:58 by frudello          #+#    #+#             */
/*   Updated: 2022/10/04 18:10:54 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	philo_printo(t_config *in, char *status)
{
	long long	now;

	sem_wait(in->write);
	now = delta_time(in->timing);
	printf("%lld %d %s\n", now, in->id + 1, status);
	sem_post(in->write);
}

void	philo_print(t_config *in, char *status)
{
	long long	now;

	die_check(in);
	sem_wait(in->write);
	now = delta_time(in->timing);
	printf("%lld %d %s\n", now, in->id + 1, status);
	sem_post(in->write);
}
