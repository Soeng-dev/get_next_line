#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


void 	putstr(char *s)
{
	if (!s)
		return ;
	while(*s)
	{	write(1, s, 1);
		s++;
	}
}

void	main(int ac, char *av[])
{
	int	fd = open("./for_test.txt", O_RDWR);
	char *read = (char *)malloc(2);
	*read = '\0';
	int i = SUCCESS;
	(i = get_next_line(fd, &read)) == SUCCESS;
		printf("%d|		|%s\n",i, read);

	(i = get_next_line(fd, &read)) == SUCCESS;
		printf("%d|		|%s\n",i, read);
	(i = get_next_line(fd, &read)) == SUCCESS;
		printf("%d|		|%s\n",i, read);
}
