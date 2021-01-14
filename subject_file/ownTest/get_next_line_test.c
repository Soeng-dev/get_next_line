#include "../get_next_line.h"
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

void	main(int argc, char *argv[])
{
	volatile int fd;
	if (argc < 2)
		fd = open("./for_test.txt", O_RDWR);
	else
		fd = atoi(argv[1]);
	char 	* r= NULL;
	int i = SUCCESS;
	while(i == SUCCESS)
	{
		i = get_next_line(fd, &r);
	}
	printf("\n\nresultof fd : %d\n\n",fd);
	printf("%s",r);

}
