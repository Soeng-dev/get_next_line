/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/20 19:21:26 by soekim           ###   ########.fr       */
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
	unread = 1;
	while (1)
	{
		if (!next || next >= backup + BUFFER_SIZE)
		{
			result = read(fd, backup, BUFFER_SIZE);
			for (int i = result; i <= BUFFER_SIZE; i++)
				backup[i] = '\0';
			//printf("read len : %d\ncontents\n%s////\n---------------------\n",result, backup);
			if (!next && result == END)
			{
				*line = (char *)malloc(1);
				**line = '\0';
				return (END);
			}
			if (result == ERROR || result == END)
				return (result);
			unread = result;
			next = backup;
		}
		else if (unread == 0)
			return (END);
			//printf("unread : %d\n", unread);
		result = strcat_del(line, next, '\n');
		if (result == ERROR)
			return (ERROR);
		unread -= result;
		next += result;
		//printf("next : %p||	%s\n",next,next);
		//printf("oneloopdone=====================\n");
	}
	return (SUCCESS);
}
