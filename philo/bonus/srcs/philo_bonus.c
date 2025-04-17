/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:12:05 by apintaur          #+#    #+#             */
/*   Updated: 2025/03/04 20:38:41 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"
#include <signal.h>

#define US_TO_MS 1000LL

static void	ft_philo_handle_one(t_philosopher *philo);
static void	ft_philo_child(t_philosopher *philo);
static void	ft_waitforchilds(t_philosopher *philo);

void	ft_philosophers(int argc, char *argv[])
{
	t_philosopher	*philos;
	pid_t			*pids;
	int				i;

	if (!ft_philo_init(&philos, argc, argv))
		return ;
	i = 0;
	pids = philos->consts->pids;
	while (i < philos->consts->max_philos)
	{
		usleep(100);
		pids[i] = fork();
		if (philos->consts->pids[i] == -1)
		{
			ft_philo_destroy(philos);
			ft_philo_unlinksems();
			exit (EXIT_FAILURE);
		}
		else if (pids[i] == 0)
			ft_philo_child(philos);
		philos = philos->next;
		i++;
	}
	ft_waitforchilds(philos);
}

static void	ft_philo_child(t_philosopher *philo)
{
	if (philo->consts->max_philos == 1)
		ft_philo_handle_one(philo);
	while (philo->checks.meals != philo->consts->max_meals)
	{
		ft_philo_eat(philo);
		ft_philo_sleep(philo);
		ft_philo_think(philo);
	}
	ft_philo_destroy(philo);
	exit (EXIT_SUCCESS);
}

static void	ft_philo_handle_one(t_philosopher *philo)
{
	ft_safeprint(philo, "has taken a fork");
	usleep(philo->consts->deadline_philos);
	printf("%lld %d died\n", ft_get_ms(), philo->pos);
	ft_philo_destroy(philo);
	exit (EXIT_FAILURE);
}

static void	ft_waitforchilds(t_philosopher *philo)
{
	int		status;
	int		i;
	pid_t	pid;

	pid = waitpid(-1, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
	{
		i = 0;
		while (i < philo->consts->max_philos)
		{
			if (philo->consts->pids[i] != pid)
				kill(philo->consts->pids[i], SIGKILL);
			i++;
		}
	}
	status = 1;
	while (status > 0)
		status = waitpid(-1, NULL, 0);
	ft_philo_destroy(philo);
	ft_philo_unlinksems();
	exit (0);
}
