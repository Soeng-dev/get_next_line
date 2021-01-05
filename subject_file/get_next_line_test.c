#include "get_next_line.h"
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

void	main(void)
{
	int	fd = open("./for_test.txt", O_RDWR);
	char 	*read = (char *)malloc(1);
	*read = '\0';
	int i = SUCCESS;
	while(i == SUCCESS)
	{
		i = get_next_line(fd, &read);
	}
	//printf("\n\nresult\n\n");
	//printf("%s\n",read);

}
