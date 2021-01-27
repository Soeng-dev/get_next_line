/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/27 14:44:45 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	backup[OPEN_MAX][BUFFER_SIZE + 1];
	char		*next;
	char		*temp;
	int			result;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ERROR);
	next = NULL;
	temp = NULL;
	result = get_oneline_and_backup(&next, backup[fd], &temp, fd);
	if (result == ERROR)
		return (ERROR);
	*line = temp;
	if (result == END)
		return (END);
	return (SUCCESS);
}
