#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
    if(pid == -1){
        perror("pid error");
    }else if(pid == 0){
        execlp("ls","ls","-l","-d",NULL);
        printf("this is child\n");
    }else{
        sleep(1);
        printf("this is parent\n");
    }

}
