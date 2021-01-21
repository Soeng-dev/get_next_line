/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/21 16:46:42 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	backup[BUFFER_SIZE + 1];
	static char	*next;
	int		result;
	int		unread;	

	if (!line || BUFFER_SIZE < 0)
		return (ERROR);
	while (1)
	{
		if (!next || next >= backup + BUFFER_SIZE)
		{
			if ((result = read(fd, backup, BUFFER_SIZE)) == ERROR)
				return (ERROR);
			//subsitute for loop to function
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
		else if (unread == 0)
			return (END);
		if (next > backup && *(next - 1) == '\n')
			*line = NULL;
		if ((result = strcat_del(line, next, '\n')) == ERROR)
			return (ERROR);
		unread -= result;
		next += result;
		if (*(next - 1) == '\n')
			return (SUCCESS);
	}
}
