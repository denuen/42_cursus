/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:03:29 by apintaur          #+#    #+#             */
/*   Updated: 2025/04/18 00:32:49 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

static t_constraints	*ft_init_constraints(int argc, char *argv[]);

int	ft_philo_init(t_philosopher **philo, int argc, char *argv[])
{
	int				i;
	t_constraints	*consts;
	t_philosopher	*tmp;

	*philo = NULL;
	consts = ft_init_constraints(argc, argv);
	if (!consts)
		return (0);
	i = 0;
	while (i < consts->max_philos)
	{
		tmp = ft_philo_new(i, consts);
		if (!tmp)
		{
			ft_philo_destroy(*philo);
			return (0);
		}
		ft_philo_addback(philo, tmp);
		i++;
	}
	(*philo)->consts->epoch = ft_get_ms();
	return (1);
}

static void	ft_philo_input_error(void)
{
	printf("Error: invalid input.\nMake sure at_ll numbers are > 0\n\
Usage: <max_philos> <deadline_philos> <deadline_meals> <deadline_sleeps> \
(<max_meals> opt)\n");
}

static int	ft_validate_consts(t_constraints *consts, int argc, char *argv[])
{
	if (argc == 6)
		consts->max_meals = ft_atoi(argv[5]);
	else
		consts->max_meals = INT_MIN;
	if (consts->max_philos <= 0 || consts->deadline_philos < 0
		|| consts->deadline_meals < 0 || consts->deadline_sleeps < 0
		|| (consts->max_meals < 0 && consts->max_meals != INT_MIN))
	{
		ft_philo_input_error();
		free(consts);
		return (0);
	}
	consts->pids = (pid_t *) malloc(sizeof(pid_t) * consts->max_philos);
	if (!consts->pids)
	{
		free (consts);
		return (0);
	}
	return (1);
}

static void	ft_philo_set_sems(t_constraints *consts)
{
	sem_unlink("/print_sem");
	sem_unlink("/fork_sem");
	sem_unlink("/death_sem_sem");
	consts->print_sem = sem_open("/print_sem", O_CREAT | O_RDWR, 0664, 1);
	consts->death_sem = sem_open("/death_sem_sem", O_CREAT | O_RDWR, 0664, 1);
	consts->forks = sem_open("/fork_sem", O_CREAT \
| O_RDWR, 0664, consts->max_philos);
}

static t_constraints	*ft_init_constraints(int argc, char *argv[])
{
	t_constraints	*consts;

	if (argc != 5 && argc != 6)
	{
		ft_philo_input_error();
		return (NULL);
	}
	consts = malloc(sizeof(t_constraints));
	if (!consts)
		return (NULL);
	consts->annihilation = FALSE;
	consts->max_philos = ft_atoi(argv[1]);
	consts->deadline_philos = ((t_ll)ft_atoi(argv[2]));
	consts->deadline_meals = ((t_ll)ft_atoi(argv[3]) * 1000);
	consts->deadline_sleeps = ((t_ll)ft_atoi(argv[4]) * 1000);
	if (!ft_validate_consts(consts, argc, argv))
		return (NULL);
	ft_philo_set_sems(consts);
	return (consts);
}
