/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:35:35 by apintaur          #+#    #+#             */
/*   Updated: 2025/04/18 00:34:44 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <unistd.h>

void	ft_safesleep(t_ll us);

static int	ft_philo_deadoralive(t_philosopher *philo)
{
	if (((ft_get_ms() - philo->consts->epoch) - philo->checks.last_meal) \
>= philo->consts->deadline_philos)
	{
		ft_safeprint(philo, "died");
		philo->consts->annihilation = TRUE;
		return (0);
	}
	return (1);
}

void	ft_philo_eat(t_philosopher *philo)
{
	int	alive;

	ft_philo_lock(philo);
	alive = ft_philo_deadoralive(philo);
	if (alive)
	{
		ft_safeprint(philo, "is eating");
		philo->checks.last_meal = ft_get_ms() - philo->consts->epoch;
		philo->checks.meals++;
		ft_safesleep(philo->consts->deadline_meals);
	}
	ft_philo_unlock(philo);
}

void	ft_philo_sleep(t_philosopher *philo)
{
	ft_safeprint(philo, "is sleeping");
	ft_safesleep(philo->consts->deadline_sleeps);
}

void	ft_philo_think(t_philosopher *philo)
{
	ft_safeprint(philo, "is thinking");
	ft_safesleep(100);
}
