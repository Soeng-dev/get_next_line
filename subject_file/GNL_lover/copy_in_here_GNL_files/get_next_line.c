/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/26 20:16:19 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char *backup[OPEN_MAX];
	static char	buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			is_oneline;
	int			result;

	if (fd < 0 || !line)
		return (ERROR);
	result = 1;
	is_oneline = 0;
	temp = NULL;
	while (!is_oneline)
	{
		if (!backup[fd])
		{
			if ((result = read(fd, buffer, BUFFER_SIZE)) == ERROR)
				return (ERROR);
			buffer[result] = '\0';
			backup[fd] = buffer;
			for (int i  = 0; i< result; i ++)
				printf("%d	",backup[fd][i]);
			printf("\n");
//			printf("result : %d\n",result);
		}
		printf("before : %p,%d\n", backup[fd],*(backup[fd]));
		backup[fd] += strcat_del(&temp, backup[fd], '\n');
		if (*(backup[fd]) == '\n' || result == END)
			is_oneline = 1;
		if (*(backup[fd]) == '\n')
			++backup[fd];
			//printf("after : %p,%d\n", backup[fd],*(backup[fd]));
		if (*(backup[fd]) == '\0')
			backup[fd] = NULL;
	}
	*line = temp;
	if (result == END)
	{
		backup[fd] = NULL;
		return (END);
	}
	return (SUCCESS);
}
