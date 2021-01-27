/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/27 12:29:20 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dst, const char *src, int len)
{
	if (!dst || !src)
		return (dst);
	while (*src && --len >= 0)
	{
		*dst = *src;
		dst++;
		src++;
	}
	return (dst);
}

int		strdel_len(char *s, char delimiter)
{
	int		len;

	if (!s)
		return (0);
	len = 0;
	while (*s && *s != delimiter)
	{
		s++;
		len++;
	}
	return (len);
}

int		strcat_del(char **line, char *to_catenate, char delimiter)
{
	int		line_len;
	int		cat_len;
	char	*tab;
	char	*newstr;

	if (!to_catenate)
		return (0);
	line_len = strdel_len(*line, '\0');
	cat_len = strdel_len(to_catenate, delimiter);
	if (!(newstr = (char *)malloc(line_len + cat_len + 1)))
		return (ERROR);
	tab = ft_strncpy(newstr, *line, line_len);
	tab = ft_strncpy(tab, to_catenate, cat_len);
	*tab = '\0';
	if (*line)
		free(*line);
	*line = newstr;
	return (cat_len);
}

int		allocate_oneline(char **next, char *buffer, char **temp, int fd)
{
	int is_oneline;
	int result;

	is_oneline = 0;
	result = 1;
	while (!is_oneline)
	{
		if (!(*next))
		{
			if ((result = read(fd, buffer, BUFFER_SIZE)) == ERROR)
				return (ERROR);
			buffer[result] = '\0';
			*next = buffer;
		}
		*next += strcat_del(temp, *next, '\n');
		if (**next == '\n' || result == END)
			is_oneline = 1;
		if (**next == '\n')
			++(*next);
		if (**next == '\0')
			*next = NULL;
	}
	return (result);
}

void	ft_memmove()
