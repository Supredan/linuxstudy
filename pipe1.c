#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int fd[2];
	pid_t pid;
	
	int ret = pipe(fd);
	if (ret == -1)
	{
		perror("pipe error");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		exit(1);
	}else if (pid == 0)
	{//read 
		close(fd[1]);
		char buf[1024];
		ret = read(fd[0], buf, sizeof(buf));	
		if (ret == 0)
		{
			printf("----------");
		}
		write(STDOUT_FILENO, buf, ret);
	}else
	{//write
		close(fd[0]);
		write(fd[1], "hello pipe\n", sizeof("hello pipe\n"));
	}
	return 0;
}
