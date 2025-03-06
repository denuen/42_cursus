/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:16:10 by apintaur          #+#    #+#             */
/*   Updated: 2025/03/06 07:06:06 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/includes/libft.h"

static void	signal_sem(int pid)
{
	kill(pid, SIGUSR2);
}

void	server(int sig, siginfo_t *info, void *context)
{
	static int				i = 8;
	static unsigned char	c = 0x0;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << --i);
	else
		i--;
	if (i == 0)
	{
		if (c == '\0')
			write (1, "\n", 1);
		else
			write(1, &c, 1);
		i = 8;
		c = 0x0;
	}
	signal_sem(info->si_pid);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	sa.sa_sigaction = server;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
