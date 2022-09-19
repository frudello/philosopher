/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:34:20 by frudello          #+#    #+#             */
/*   Updated: 2022/09/19 19:46:45 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_struct(int ac, char **av, t_parse *parse)
{
	if	((check_argoments(ac, av)))
	{
		printf("solo numeri coglione, driiiiiiiinnnn");
		return (1);
	}
	parse->n_p = ft_atoi(av[1]);
	parse->dieTime = ft_atoi(av[2]);
	parse->eatTime = ft_atoi(av[3]);
	parse->sleapTime = ft_atoi(av[4]);
	if (ac = 6)
		parse->numberEating = ft_atoi(av[5]);
	else
		parse->numberEating = -1;
	return (0);
}

void	init_fork(t_dati *dati)
{
	int	i;

	i = 0;
	dati->fork = malloc(sizeof(int *) * (dati->parse->n_p + 1));
	while (i < dati->parse->n_p)
	{
		dati->fork[i] = malloc(sizeof(int));
		dati->fork[i][0] = 1;
		i++;
	}
	dati->fork[i] = dati->fork[0];
}

void	init_mutex(t_dati *dati)
{
	int	i;

	i = 0;
	dati->Mkill = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(Mkill, NULL);
	dati->Mprint = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(Mprint, NULL);
	dati->Mfork = malloc(sizeof(pthread_mutex_t) * (dati->parse->n_p + 1));
	while (i < dati->parse->n_p)
	{
		dati->Mfork[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(dati->Mfork[i][0], NULL);
		i++;
	}
	dati->Mfork[i] = dati->Mfork[0];
}

void	init_tread(t_dati *dati)
{
	int	i;

	i = -1;
	dati->p_phtread = malloc(sizeof(phtread_t *) * (dati->parse->n_p + 1));
	while (++i < dati->parse->n_p)
		dati->p_phtread[i] = malloc(sizeof(pthread_t));
}

void	init_philo(t_philo **philo, t_dati *dati)
{
	int	i;

	i = 0;
	while(i < dati->parse->n_p)
	{
		philo->id_p[i] = i + 1;
	}
}