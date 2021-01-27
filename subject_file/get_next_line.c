/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2021/01/27 09:12:44 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char *backup;
	static char	buffer[BUFFER_SIZE + 1];
	//char		*temp;
	int			is_oneline;
	int			result;

	if (fd < 0 || !line)
		return (ERROR);
	result = 1;
	is_oneline = 0;
	//temp = NULL;
	while (!is_oneline)
	{
		if (!backup)
		{
			if ((result = read(fd, buffer, BUFFER_SIZE)) == ERROR)
				return (ERROR);
			buffer[result] = '\0';
			backup = buffer;
		}
		backup += strcat_del(line/*&temp*/, backup, '\n');
		if (*(backup) == '\n' || result == END)
			is_oneline = 1;
		if (*(backup) == '\n')
			++backup;
		if (*(backup) == '\0')
			backup = NULL;
	}
	//*line = temp;
	if (result == END)
	{
		backup = NULL;
		return (END);
	}
	return (SUCCESS);
}
