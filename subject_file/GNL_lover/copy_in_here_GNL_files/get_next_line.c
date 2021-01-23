/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/24 02:57:07 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char *backup[OPEN_MAX];
	char		*temp;
	//int			is_oneline;
	int			bufsize;

	if (fd < 0 || !line)
		return (ERROR);
	is_oneline = 0;
	temp = NULL;
	//make backup[fd] = NULL when *backup[fd] = \0;
	//revise strcat_del for making temp = malloc(1), temp[0] = '\0'; when !backup[fd]
	while (1)//!is_oneline)
	{
		if (!backup[fd])
			if ((bufsize = read(fd, backup[fd], BUFFER_SIZE)) == ERROR)
				return (ERROR);	
		backup[fd][bufsize] = '\0';
		backup[fd] += strcat_del(&temp,backup[fd], '\n');
		if (*(backup[fd] - 1) == '\n' || bufsize = END)
		{
			*line = temp;
			if (bufsize)
				return (SUCCESS);
			else if (bufsize == END)
				return (END);
		}
	}
}
