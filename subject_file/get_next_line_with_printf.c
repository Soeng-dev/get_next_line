/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/24 08:46:12 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char *backup[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			is_oneline;
	int			result;

	if (fd < 0 || !line)
		return (ERROR);
	is_oneline = 0;
	temp = NULL;
	if (!backup[fd])
		*(backup[fd] = buffer) = '\0';
	while (!is_oneline)
	{
		if (*backup[fd] == '\0')
			if ((result = read(fd, buffer, BUFFER_SIZE)) == ERROR)
				return (ERROR);
		//printf("read contents below:\n%s///\n",buffer);
		buffer[result] = '\0';
		//printf("before cat\n");
		backup[fd] = buffer + strcat_del(&temp,buffer, '\n');// - 1;
		if (*backup[fd] == '\n' || result == END)
			is_oneline = 1;
		printf("is oneline %d	result : %d\n	bu : %d	bf:%d\n",is_oneline,result, (int)*(backup[fd]),(int)buffer[result]);
		if (*backup[fd] == '\n')
			backup[fd]++;
	}
	*line = temp;
	if (result == END)
		return (END);
	return (SUCCESS);
}
