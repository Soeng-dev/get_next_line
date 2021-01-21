/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/21 12:35:08 by soekim           ###   ########.fr       */
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
	return (++len);
}

int		strcat_del(char **line, char *to_catenate, char delimiter)
{
	int		cat_len;
	char	*tab;
	char	*newstr;

	if (!to_catenate)
		return (0);
	cat_len = strdel_len(to_catenate, delimiter);
	//printf("cat len : %d\n", cat_len);
	if (!(newstr = (char *)malloc(ft_strlen(*line)+ cat_len + 1)))
		return (ERROR);
	tab = ft_strcpy(newstr, *line);
	tab = ft_strncpy(tab, to_catenate, cat_len);
	*tab = '\0';
	//if (line)
		//free(*line);
	*line = newstr;
	return (cat_len);
}
