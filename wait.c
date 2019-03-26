#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid,wpid;
    int status;
    pid = fork();
    if(pid == 0){
        printf("this is child%d \n",getppid());
        sleep(5);
        printf("child die------\n");
    }else if(pid > 0){
        wpid = wait(NULL);
        printf("child wpid = %d\n",wpid);
        while(1){
            sleep(2);
            printf("this is parent,pid = %d,ppid = %d\n",getpid(),getppid());
        }
    }
    return 0;
}
