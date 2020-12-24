#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	maketxt(int fd, int len, int line)
{
	int temp = len;
	while (--line >= 0)
	{
		len = temp;
		char n = '1';
		while (--len >= 0)
		{
			write(fd, &n , 1);
			n++;
		}
		write(fd, "\n", 1);
	}
}

void	main(int ac, char *av[])
{
	close(0);
	int fd =  open("./for_test.txt", O_CREAT | O_RDWR | O_TRUNC);
	if(ac)
		maketxt(fd, atoi(av[1]), atoi(av[2]));
	close(fd);
}
