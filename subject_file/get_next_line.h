/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2020/11/29 10:28:28 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>

# define ERROR		-1
# define END		0
# define SUCCESS	1

struct	s_file
{
	char	**line;
	int		fd;
};
struct	s_cat
{
	char	*str;
	char	del;
};
typedef struct s_file	t_file;
typedef struct s_cat	t_cat;

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		strdel_len(char *s, char delimiter);
int		strcat_del(char **line, char *to_catenate, char delimiter);
int		min(int a, int b);
int		get_next_line(int fd, char **line);
#endif
