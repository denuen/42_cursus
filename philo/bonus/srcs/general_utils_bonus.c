/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:02:04 by apintaur          #+#    #+#             */
/*   Updated: 2025/03/04 20:36:19 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"
#include <sys/time.h>

static int	ft_isspace(const char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	ft_isdigit(const char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *s)
{
	int	i;
	int	value;
	int	sign;

	if (!s)
		return (0);
	i = 0;
	value = 0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(s[i]))
		return (-1);
	while (ft_isdigit(s[i]))
	{
		value = value * 10 + (s[i] - '0');
		i++;
	}
	return (value * sign);
}

t_ll	ft_get_ms(void)
{
	struct timeval	tv;
	t_ll			current_ts;

	gettimeofday(&tv, NULL);
	current_ts = ((t_ll)(tv.tv_sec * 1000)) + tv.tv_usec / 1000;
	return (current_ts);
}

t_ll	ft_get_us(void)
{
	struct timeval	tv;
	t_ll			current_ts;

	gettimeofday(&tv, NULL);
	current_ts = ((t_ll)(tv.tv_sec * 1000000)) + tv.tv_usec;
	return (current_ts);
}
