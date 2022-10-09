/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:32:20 by frudello          #+#    #+#             */
/*   Updated: 2022/10/04 18:18:43 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_meal(t_config *in)
{
	static int	meals;

	if (meals == in->num_of_eat -1)
	{
		free(in->pid);
		exit (1);
	}
	else if (meals < in->num_of_eat)
		meals += 1;
}
