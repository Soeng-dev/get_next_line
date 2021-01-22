/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/22 16:52:06 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char backup[BUFFER_SIZE + 1];
	static char *newline;
	char		*temp;
	int			result;
// when reads empty file, line = malloc1, line ='\0'
	newline = backup;
	while (*newline != '\n')
	{
		if ((result = read(fd, backup, BUFFER_SIZE)) == ERROR)
			return (ERROR);
		else if (result == END)
		{
			//substitue to function
			if (!next)
			{
				*line = (char *)malloc(1);
				(*line)[0] = '\0';
			}
			return (END);
		}
		if 
		
	}
	init_arr(backup);
	return (SUCCESS);
}
