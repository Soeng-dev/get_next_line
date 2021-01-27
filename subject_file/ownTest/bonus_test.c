#include "../GNL_lover/copy_in_here_GNL_files/get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void 	putstr(char *s, int fd)
{
	if (!s)
		return ;
	while(*s)
	{	write(fd, s, 1);
		s++;
	}
}

int		main()
{
	volatile int fd;
		fd = open("./for_test.txt", O_RDWR);
	char 	* r= NULL;
	//char buf[100];
	int i = SUCCESS;

//	while ((i = read(fd, buf, 4)));
//	for (int i = 0; i < 4; i++)
//		printf("i:%d|%d\n", i, (int)buf[i]);

	while((i = get_next_line(fd, &r)) == SUCCESS)
		printf("return :%d		len:%ld		|%s\n",i,strlen(r),r);
}
