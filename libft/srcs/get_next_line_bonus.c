/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:42:10 by apintaur          #+#    #+#             */
/*   Updated: 2025/01/08 08:22:21 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 15
#endif

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_createbuffer(int fd);
void	ft_freebuff(char *buffer);

char	*get_next_line(int fd)
{
	static char	*join[FOPEN_MAX];
	char		*buffer;
	ssize_t		i;

	buffer = ft_createbuffer(fd);
	if (buffer == NULL)
		return (NULL);
	i = read (fd, buffer, BUFFER_SIZE);
	while (i > 0)
	{
		buffer[i] = '\0';
		join[fd] = ft_strnjoin(join[fd], buffer, i);
		i = ft_strrlen(join[fd], '\n');
		if (join[fd][i] == '\n')
		{
			ft_freebuff (buffer);
			return (ft_strupdate(&join[fd], i));
		}
		i = read (fd, buffer, BUFFER_SIZE);
	}
	ft_freebuff(buffer);
	if (join[fd])
		return (ft_strupdate(&join[fd], ft_strrlen(join[fd], '\n')));
	return (NULL);
}

char	*ft_createbuffer(int fd)
{
	char	*new;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	new = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new)
		return (NULL);
	return (new);
}

void	ft_freebuff(char *buffer)
{
	if (buffer)
	{
		free (buffer);
		buffer = NULL;
	}
}
