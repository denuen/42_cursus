/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:16:13 by apintaur          #+#    #+#             */
/*   Updated: 2025/02/22 20:58:08 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/includes/libft.h"

static volatile sig_atomic_t	g_wait = 0;

void	semaphore_handler(int sig)
{
	(void)sig;
	g_wait = 1;
}

void	send_msg(int pid, char character)
{
	unsigned char	c;
	int				i;

	i = 8;
	c = (unsigned char)character;
	while (i--)
	{
		g_wait = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_wait)
			pause();
	}
}

void	client(int pid, const char *string)
{
	int	i;

	i = -1;
	if (string)
		while (string[++i])
			send_msg(pid, string[i]);
	send_msg(pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
		return (1);
	sa.sa_handler = semaphore_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	client(ft_atoi(argv[1]), argv[2]);
	return (0);
}
