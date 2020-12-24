/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:32:19 by soekim            #+#    #+#             */
/*   Updated: 2020/11/29 17:47:48 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	backup[BUFFER_SIZE + 1];
	static char	*next;
	int			len;

	len = BUFFER_SIZE;
	while (len == BUFFER_SIZE)
	{
		if (!next || next >= backup + BUFFER_SIZE)
		{
			len = read(fd, backup, BUFFER_SIZE);
			printf("read len : %d", len);
			if (len == ERROR || len == END)
				return (len);
			next = backup;
		}
		len = cat_str_del(line, backup, '\n', fd);
		if (len == ERROR || len == END)
			return (len);
		next += (len + 1);
		printf("1   %p\n", next);
	}
	return (SUCCESS);
}
