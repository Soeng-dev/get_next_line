 #include "../GNL_lover/copy_in_here_GNL_files/get_next_line.h"
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

void	main()
{
	volatile int fd;
		fd = open("./for_test.txt", O_RDWR);
	char 	* r= NULL;
	char buf[100];
	int i = SUCCESS;

	char k[1];
	k[0] = 0;
	write(fd,"\n",1);
	write(fd,k,1);
//	while ((i = read(fd, buf, 4)));
//	for (int i = 0; i < 4; i++)
//		printf("i:%d|%d\n", i, (int)buf[i]);
//
//
//
//	while((i = get_next_line(fd, &r))== SUCCESS)
//		printf("return :%d		len:%d		|%s",i,strlen(r),r);
//		
//	char *buff[10];
//	int n = read(fd,buff[3],10);
//	printf("%d:%s \n", n, buff[3]);
//
}
