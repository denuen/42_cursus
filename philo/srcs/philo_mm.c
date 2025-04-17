/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:37:06 by apintaur          #+#    #+#             */
/*   Updated: 2025/03/04 20:31:47 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

t_philosopher	*ft_philo_new(const int pos, t_constraints *consts)
{
	t_philosopher	*tmp;

	tmp = malloc(sizeof(t_philosopher));
	if (!tmp)
		return (NULL);
	tmp->pos = pos + 1;
	tmp->consts = consts;
	tmp->checks.last_meal = 0;
	tmp->checks.meals = 0;
	tmp->next = tmp;
	tmp->prev = tmp;
	pthread_mutex_init(&tmp->fork, NULL);
	return (tmp);
}

void	ft_philo_addback(t_philosopher **philo, t_philosopher *tmp)
{
	if (!philo || !tmp)
		return ;
	if (!*philo)
		*philo = tmp;
	else
	{
		tmp->next = (*philo);
		tmp->prev = (*philo)->prev;
		(*philo)->prev->next = tmp;
		(*philo)->prev = tmp;
	}
}

void	ft_philo_destroy(t_philosopher *philo)
{
	t_philosopher	*tmp;

	if (!philo)
		return ;
	pthread_mutex_destroy(&philo->consts->print_mutex);
	free (philo->consts);
	philo->prev->next = NULL;
	while (philo)
	{
		tmp = philo;
		philo = philo->next;
		pthread_mutex_destroy(&tmp->fork);
		free(tmp);
	}
}
