/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/22 19:51:45 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char backup[BUFFER_SIZE + 1];
	static char *next;
	char		*temp;
	int			result;

	if (fd < 0 || !line)
		return (ERROR);
	next = backup + 1;
	temp = NULL;
	while (*(next - 1) != '\n')
	{
		if (next == backup || next >= backup + BUFFER_SIZE)
		{
			if ((result = read(fd, backup, BUFFER_SIZE)) == ERROR)
				return (ERROR);
			ft_memset((void*)(backup + result), '\0', BUFFER_SIZE + 1 - result);
			if (result == END)
			{
				printf("here\n");
				if (next == backup)
				{
					*line = (char *)malloc(1);
					(*line)[0] = '\0';
				}
				else
					*line = temp;
				return (END);
			}
		}
		ft_memset((void*)(backup + result), '\0', BUFFER_SIZE + 1 - result);
		//should make strcat_del malloc temp = malloc1, temp[0] = '\0' when empty file read
		if ((result = strcat_del(&temp, next, '\n')) == ERROR)
			return (ERROR);
		next += result;
	}
	*line = temp;
	return (SUCCESS);
}
