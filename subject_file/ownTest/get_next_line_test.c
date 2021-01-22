 #include "../GNL_lover/copy_in_here_GNL_files/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void 	putstr(char *s, int fd)
{
	if (!s)
		return ;
	while(*s)
	{	write(fd, s, 1);
		s++;
	}
}

void	main()
{
	volatile int fd;
		fd = open("./for_test.txt", O_RDWR);
	char 	* r= NULL;
	char buf[100];
	int i = SUCCESS;

	while(i == SUCCESS)
	{
		i = get_next_line(fd, &r);
		printf("|%s",r);
	}
}
