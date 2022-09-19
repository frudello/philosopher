/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:29:04 by frudello          #+#    #+#             */
/*   Updated: 2022/09/19 19:43:48 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int ac, char **av)
{
	t_philo	**philo;
	t_dati	*dati;

	dati = malloc(sizeof(t_dati));
	dati->parse = malloc(sizeof(t_parse));
	if (ac < 5 || ac > 6)
		printf("Wrong number of argoments");
	if (init_struct(ac, av, dati->parse))
	{
		free(dati->parse);
		free(dati);
	}
	init_fork(dati);
	init_mutex(dati);
	init_tread(dati);
	philo = malloc(sizeof(t_philo) * dati->parse->n_p)
	init_philo(philo);
}