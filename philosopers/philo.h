/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:44:26 by frudello          #+#    #+#             */
/*   Updated: 2022/09/19 19:35:56 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define MORTO "died ☠️"

enum e_status
{
	ALIVE,
	DIED,
};

enum e_fork
{
	TAKEN,
	NOT_TAKEN,
};

enum e_stage
{
	EATING,
	SLEEPING,
	FINISH,
};

typedef struct s_parse
{
	int	n_p;
	int	dieTime;
	int	eatTime;
	int	sleapTime;
	int	numbrtEating;
}		t_parse;

typedef struct s_dati
{
	int				kill;
	int				**fork;
	size_t			timing;
	t_parse			*parse;
	pthread_t		**p_phtread;
	pthread_mutex_t	*Mkill;
	pthread_mutex_t	*Mprint;
	pthread_mutex_t	**Mfork;
}		t_dati;

typedef struct s_philo
{
	int				id_p;
	int				dx;
	int				sx;
	int				status;
	int				stage;
	int				fine;
	size_t			last_meal;
	size_t			last_cange;
	t_dati			dati;
}		t_philo;

int		check_argoments(int ac, char **av);
int		ft_atoi(const char *str);
int		init_struct(int ac, char **av, t_parse *parse);
void	init_fork(t_dati *dati);

#endif