/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:26:05 by apintaur          #+#    #+#             */
/*   Updated: 2025/03/04 19:59:01 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE 1
# define FALSE 0

# include <pthread.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef long long	t_ll;
typedef struct s_constraints
{
	int					annihilation;
	int					max_philos;
	int					max_meals;
	t_ll				epoch;
	t_ll				deadline_philos;
	t_ll				deadline_meals;
	t_ll				deadline_sleeps;
	pthread_mutex_t		print_mutex;
}	t_constraints;

typedef struct s_check
{
	int		meals;
	t_ll	last_meal;
}	t_check;

typedef struct s_philosopher
{
	pthread_mutex_t			fork;
	pthread_t				id;
	int						pos;
	t_check					checks;
	t_constraints			*consts;
	struct s_philosopher	*next;
	struct s_philosopher	*prev;
}	t_philosopher;

//Philosophers' main function [philo.c]
void			ft_philosophers(int argc, char *argv[]);

//Philosopers' memory management functions [philo_mm.c]
void			ft_philo_addback(t_philosopher **philo, t_philosopher *tmp);
t_philosopher	*ft_philo_new(const int pos, t_constraints *consts);
void			ft_philo_destroy(t_philosopher *philo);

//Philosophers' init parameters function [philo_init.c]
int				ft_philo_init(t_philosopher **philo, int argc, char *argv[]);

//Philosophers' operations functions [philo_operations.c]
void			ft_philo_eat(t_philosopher *philo);
void			ft_philo_sleep(t_philosopher *philo);
void			ft_philo_think(t_philosopher *philo);

//Philosophers' operations utility functions [philo_utils.c]
void			ft_safeprint(t_philosopher *philo, char *status);
void			ft_philo_lock(t_philosopher *philo);
void			ft_philo_unlock(t_philosopher *philo);

//General utility functions[general_utils.c]
t_ll			ft_get_ms(void);
t_ll			ft_get_us(void);
int				ft_atoi(const char *s);

#endif
