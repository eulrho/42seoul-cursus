#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int main() 
{
	int	fd = open("test.txt", O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
	char *res;
	char buff[1024];

	printf("%zd", read(fd, buff, BUFFER_SIZE));

	// for (int i=0; i<5; i++)
	// {
	// 	res = get_next_line(fd);
	// 	if (res == NULL)
	// 	{
	// 		printf("end\n");
	// 		break ;
	// 	}
	// 	printf("%s", res);
	// }
	close(fd);
	return (0);
}