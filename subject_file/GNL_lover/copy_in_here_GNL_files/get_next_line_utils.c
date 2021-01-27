/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/27 10:02:50 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s)
	{
		while (*(s++))
			len++;
	}
	return (len);
}

char	*ft_strcpy(char *dst, const char *src)
{
	if (!dst || !src)
		return (dst);
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	return (dst);
}

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
	int		cat_len;
	char	*tab;
	char	*newstr;

	if (!to_catenate)
		return (0);
	cat_len = strdel_len(to_catenate, delimiter);
	if (!(newstr = (char *)malloc(ft_strlen(*line) + cat_len + 1)))
		return (ERROR);
	tab = ft_strcpy(newstr, *line);
	tab = ft_strncpy(tab, to_catenate, cat_len);
	*tab = '\0';
	if (*line)
		free(*line);
	*line = newstr;
	return (cat_len);
}

int		make_oneline(char **backup, char *buffer, char **temp, int fd)
{
	int is_oneline;
	int read_result;

	is_oneline = 0;
	read_result = 1;
	while (!is_oneline)
	{
		if (!(*backup))
		{
			if ((read_result = read(fd, buffer, BUFFER_SIZE)) == ERROR)
				return (ERROR);
			buffer[read_result] = '\0';
			*backup = buffer;
		}
		*backup += strcat_del(temp, *backup, '\n');
		if (**backup == '\n' || read_result == END)
			is_oneline = 1;
		if (**backup == '\n')
			++(*backup);
		if (**backup == '\0')
			*backup = NULL;
	}
	return (read_result);
}
