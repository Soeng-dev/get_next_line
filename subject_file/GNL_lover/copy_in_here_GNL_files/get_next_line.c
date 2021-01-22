/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/22 11:16:30 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	backup[BUFFER_SIZE + 1];
	static char	*next;
	int			result;
	int			unread;
	int			is_newline;	

	if (!line || BUFFER_SIZE <= 0)
		return (ERROR);
	while (1) 
	{
		if (!next || next >= backup + BUFFER_SIZE)
		{
			if ((result = read(fd, backup, BUFFER_SIZE)) == ERROR)
				return (ERROR);
			for (int i = result; i <= BUFFER_SIZE; i++)
				backup[i] = '\0';
			if (result == END)
			{
				if (!next)
				{
					*line = (char *)malloc(1);
					**line = '\0';
				}
				return (END);
			}
			unread = result;
			next = backup;
		}
		if ((result = strcat_del(line, next, '\n', &is_newline)) == ERROR)
			return (ERROR);
		unread -= result;
		next += result;
		if (is_newline)
			return (SUCCESS);
	}
}
