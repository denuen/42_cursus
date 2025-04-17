/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:12:05 by apintaur          #+#    #+#             */
/*   Updated: 2025/03/04 20:36:52 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

#define US_TO_MS 1000LL

static void	*ft_philo_handle_one(t_philosopher *philo);
void		*ft_lock_ordering(void *data);

void	ft_philosophers(int argc, char *argv[])
{
	t_philosopher	*philos;
	int				i;

	i = 0;
	if (!ft_philo_init(&philos, argc, argv))
		return ;
	while (i < philos->consts->max_philos)
	{
		pthread_create(&philos->id, NULL, ft_lock_ordering, (void *)philos);
		philos = philos->next;
		i++;
		usleep(100);
	}
	i = 0;
	while (i < philos->consts->max_philos)
	{
		pthread_join(philos->id, NULL);
		philos = philos->next;
		i++;
	}
	ft_philo_destroy(philos);
}

void	*ft_lock_ordering(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	if (philo->consts->max_philos == 1)
		return (ft_philo_handle_one(philo));
	while (philo->checks.meals != philo->consts->max_meals)
	{
		if (philo->consts->annihilation == TRUE)
			break ;
		ft_philo_eat(philo);
		ft_philo_sleep(philo);
		ft_philo_think(philo);
	}
	return (NULL);
}

static void	*ft_philo_handle_one(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->fork);
	ft_safeprint(philo, "has taken a fork");
	usleep(philo->consts->deadline_philos);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_lock(&philo->consts->print_mutex);
	printf("%lld %d died\n", ft_get_ms(), philo->pos);
	pthread_mutex_unlock(&philo->consts->print_mutex);
	return (NULL);
}
