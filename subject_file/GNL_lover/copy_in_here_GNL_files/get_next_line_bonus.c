/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/27 20:41:45 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static char	backup[OPEN_MAX][BUFFER_SIZE + 1];
	char		*next;
	char		*temp;
	int			result;

	temp = NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ERROR);
	next = backup[fd];
	temp = NULL;
	result = get_oneline_and_next(&next, backup[fd], &temp, fd);
	//printf("check next is right\nnext:%s\n", next);
	if (result == ERROR)
		return (ERROR);
	*line = temp;
	if (result == END)
		return (END);
	ft_memmove(backup[fd], next, ((backup[fd] - next) / sizeof(char *)) + BUFFER_SIZE + 1);
	//printf("check bu after memmove\nnext:%s\n",backup[fd]);
	return (SUCCESS);
}
