/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:43:56 by apintaur          #+#    #+#             */
/*   Updated: 2025/04/18 00:33:42 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"
#include <stdio.h>
#include <sys/time.h>

void	ft_safesleep(t_ll deadline)
{
	t_ll	start_us;

	start_us = ft_get_us();
	while ((ft_get_us() - start_us) < deadline)
	{
		usleep(10);
	}
}

void	ft_safeprint(t_philosopher *philo, char *status)
{
	sem_wait(philo->consts->print_sem);
	if (philo->consts->annihilation == FALSE)
	{
		printf("%lld %d %s\n", ft_get_ms() - philo->consts->epoch, \
philo->pos, status);
	}
	sem_post(philo->consts->print_sem);
}

void	ft_philo_lock(t_philosopher *philo)
{
	sem_wait(philo->consts->forks);
	ft_safeprint(philo, "has taken a fork");
	sem_wait(philo->consts->forks);
	ft_safeprint(philo, "has taken a fork");
}

void	ft_philo_unlock(t_philosopher *philo)
{
	sem_post(philo->consts->forks);
	sem_post(philo->consts->forks);
}
