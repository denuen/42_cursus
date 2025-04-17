/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mm_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:37:06 by apintaur          #+#    #+#             */
/*   Updated: 2025/04/18 00:26:44 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"
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

	sem_close(philo->consts->forks);
	sem_close(philo->consts->print_sem);
	sem_close(philo->consts->death_sem);
	free (philo->consts->pids);
	free (philo->consts);
	philo->prev->next = NULL;
	while (philo)
	{
		tmp = philo;
		philo = philo->next;
		free (tmp);
	}
}

void	ft_philo_unlinksems(void)
{
	unlink("/print_sem");
	unlink("/fork_sem");
	unlink("/death_sem_sem");
}
