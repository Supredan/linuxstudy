#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid,ppid,q;
	int n = 5,i;
	for (i = 0; i < n; i += 1)
	{
		pid = fork();
		if (pid == 0)
		{
			break;
		}else if(i == 3)
		{
			q = pid;
		}
	}
	
	if(n == i){
		sleep(n);
		printf("I am parent, pid = %d\n",getpid());
		waitpid(q, NULL, 0);
		while(1);
	}else
	{
		sleep(i);
		printf("I am %dchild, pid = %d,ppid = %d\n",i,getpid(),getppid());
	}
	
}
