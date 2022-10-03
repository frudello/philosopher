/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:32:20 by frudello          #+#    #+#             */
/*   Updated: 2022/09/27 16:33:34 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_forks(t_config *instance)
{
	int	i;

	i = 0;
	instance->forks = malloc(sizeof(pthread_mutex_t) * instance->num_philo);
	if (instance->forks == NULL)
		return (FALSE);
	while (i < instance->num_philo)
	{
		if (pthread_mutex_init(&instance->forks[i], NULL) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
