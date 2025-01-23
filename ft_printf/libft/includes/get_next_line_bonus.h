/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:42:20 by apintaur          #+#    #+#             */
/*   Updated: 2025/01/07 14:02:22 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <unistd.h>

char		*get_next_line(int fd);
size_t		ft_strrlen(const char *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strnjoin(char *s1, char *s2, ssize_t bytes);
char		*ft_strupdate(char **join, size_t i);
#endif
