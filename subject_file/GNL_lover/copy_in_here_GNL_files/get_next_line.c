/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/27 09:19:37 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char *backup;
	static char	buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			is_oneline;
	int			result;

	if (fd < 0 || !line)
		return (ERROR);
	is_oneline = 0;
	temp = NULL;
	result = make_oneline(&backup, buffer, &temp, &is_oneline, fd)
	*line = temp;
	if (result == END)
	{
		backup = NULL;
		return (END);
	}
	return (SUCCESS);
}
