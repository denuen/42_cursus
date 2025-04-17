/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:43:56 by apintaur          #+#    #+#             */
/*   Updated: 2025/04/18 00:34:51 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdio.h>
#include <sys/time.h>

void	ft_safeprint(t_philosopher *philo, char *status)
{
	pthread_mutex_lock(&philo->consts->print_mutex);
	if (philo->consts->annihilation == FALSE)
	{
		printf("%lld %d %s\n", ft_get_ms() - philo->consts->epoch, \
philo->pos, status);
	}
	pthread_mutex_unlock(&philo->consts->print_mutex);
}

void	ft_safesleep(t_ll deadline)
{
	t_ll	start_us;

	start_us = ft_get_us();
	while ((ft_get_us() - start_us) < deadline)
	{
		usleep(10);
	}
}

void	ft_philo_lock(t_philosopher *philo)
{
	if (philo->pos < philo->next->pos
		|| philo->pos == philo->consts->max_philos)
	{
		pthread_mutex_lock(&philo->fork);
		ft_safeprint(philo, "has taken a fork");
		pthread_mutex_lock(&philo->next->fork);
		ft_safeprint(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->next->fork);
		ft_safeprint(philo, "has taken a fork");
		pthread_mutex_lock(&philo->fork);
		ft_safeprint(philo, "has taken a fork");
	}
}

void	ft_philo_unlock(t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
}
