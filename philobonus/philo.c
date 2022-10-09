/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:35 by frudello          #+#    #+#             */
/*   Updated: 2022/09/27 15:56:13 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_config	demo;

	if (!check_inputs(argc, argv))
	{
		printf("Error inputs ! \n");
		return (FALSE);
	}
	if (create_philos(&demo, argv) == FALSE)
		return (1);
	if (create_forks(&demo) == FALSE)
		return (1);
	if (demo.num_philo > 1)
		create_threads(&demo);
	else
		one_philo(&demo, 0);
	ft_free(&demo);
	return (0);
}
