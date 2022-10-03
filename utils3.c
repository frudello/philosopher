/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:53:02 by frudello          #+#    #+#             */
/*   Updated: 2022/09/27 16:24:07 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(long long time)
{
	long long	tmp;

	tmp = get_time();
	usleep(time * 1000 - 20000);
	while (get_time() < tmp + time)
		continue ;
}

void	ft_free(t_config *instance)
{
	free (instance->forks);
	free (instance->philo);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	check_inputs(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (!(ft_isdigit(argv[1])) && !(ft_atoi(argv[1]) < 0))
			return (FALSE);
		if (!(ft_isdigit(argv[2])) && !(ft_atoi(argv[2]) < 0))
			return (FALSE);
		if (!(ft_isdigit(argv[3])) && !(ft_atoi(argv[3]) < 0))
			return (FALSE);
		if (!(ft_isdigit(argv[4])) && !(ft_atoi(argv[4]) < 0))
			return (FALSE);
		if (argc == 6)
		{
			if (!(ft_isdigit(argv[5])) && !(ft_atoi(argv[5]) < 0))
				return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}

int	one_philo(t_config *in, int i)
{
	if (pthread_mutex_lock(&in->forks[in->philo[i].fork_left]) != 0)
		return (FALSE);
	if (philo_print(in, in->philo[i].id, FORK_LEFT) == FALSE)
		return (FALSE);
	if (pthread_mutex_unlock(&in->forks[in->philo[i].fork_left]) != 0)
		return (FALSE);
	in->philo_dead = TRUE;
	usleep(in->input_time_to_die * 1000);
	printf("%lld %d %s\n", in->input_time_to_die, 1, DIED);
	return (TRUE);
}
