/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/27 13:55:10 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// use memmove after alloc one line
int		get_next_line(int fd, char **line)
{
	static char	backup[OPEN_MAX][BUFFER_SIZE + 1];
	char		*next;
	char		*temp;
	int			result;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ERROR);
	next = NULL
	temp = NULL;
	result = allocline_and_backup(&next, backup, &temp, fd);
	if (result == ERROR)
		return (ERROR);
	*line = temp;
	if (result == END)
	{
		backup = NULL;
		return (END);
	}
	return (SUCCESS);
}
