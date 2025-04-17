/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:22:15 by apintaur          #+#    #+#             */
/*   Updated: 2025/04/18 00:26:41 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define TRUE 1
# define FALSE 0
# define DEAD 2

# include <pthread.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

typedef long long	t_ll;
typedef struct s_constraints
{
	pid_t	*pids;
	int		annihilation;
	int		max_philos;
	int		max_meals;
	t_ll	deadline_philos;
	t_ll	deadline_meals;
	t_ll	deadline_sleeps;
	t_ll	epoch;
	sem_t	*forks;
	sem_t	*print_sem;
	sem_t	*death_sem;
}	t_constraints;

typedef struct s_check
{
	t_ll	last_meal;
	int		meals;
}	t_check;

typedef struct s_philosopher
{
	int						pos;
	struct s_philosopher	*next;
	struct s_philosopher	*prev;
	t_constraints			*consts;
	t_check					checks;
}	t_philosopher;

void			ft_philosophers(int argc, char *argv[]);

t_philosopher	*ft_philo_new(const int pos, t_constraints *consts);
void			ft_philo_destroy(t_philosopher *philo);
void			ft_philo_unlinksems(void);

void			ft_philo_addback(t_philosopher **philo, t_philosopher *tmp);
int				ft_philo_init(t_philosopher **philo, int argc, char *argv[]);

void			ft_philo_eat(t_philosopher *philo);
void			ft_philo_sleep(t_philosopher *philo);
void			ft_philo_think(t_philosopher *philo);

void			ft_safeprint(t_philosopher *philo, char *status);
void			ft_safesleep(t_ll deadline);
void			ft_philo_lock(t_philosopher *philo);
void			ft_philo_unlock(t_philosopher *philo);

t_ll			ft_get_ms(void);
t_ll			ft_get_us(void);
int				ft_atoi(const char *s);
#endif
