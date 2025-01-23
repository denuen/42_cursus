/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:29:52 by apintaur          #+#    #+#             */
/*   Updated: 2024/12/16 21:06:46 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (i < n)
		{
			((unsigned char *)s)[i] = '\0';
			i++;
		}
	}
}
