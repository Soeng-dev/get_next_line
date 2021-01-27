/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/27 11:25:26 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char *backup;
	static char	buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			result;

	if (fd < 0 || !line)
		return (ERROR);
	temp = NULL;
	result = allocate_oneline(&backup, buffer, &temp, fd);
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
