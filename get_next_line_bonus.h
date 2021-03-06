/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/28 15:22:53 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define ERROR		-1
# define END		0
# define SUCCESS	1

char		*ft_strncpy(char *dst, const char *src, int len);
int		strdel_len(char *s, char delimiter);
int		strcat_del(char **line, char *to_catenate, char delimiter);
int		get_next_line(int fd, char **line);
void		*ft_memmove(void *dst, const void *src, int len);
int		get_oneline_and_next(char **next, char *buffer, char **temp, int fd);
#endif
