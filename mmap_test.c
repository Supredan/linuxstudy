#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	int len, ret;
	char *p = NULL;
	int fd = open("mytest.txt",O_CREAT|O_RDWR, 0644);
	if(fd < 0)
	{
		perror("open error:");
		exit(1);
	}
	len = ftruncate(fd, 4);
	if (len == -1)
	{
		perror("ftruncate error:");
		exit(1);
	}
	
	p = mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	strcpy(p, "dan");
	
	ret = munmap(p, 4);
	if (ret == -1)
	{
		perror("unmap error:");
		exit(1);
	}
	close(fd);
	return 0;
}
