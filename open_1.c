#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd;
    
    fd = open("hello.txt",O_RDWR);
    if(fd == -1){
        perror("open error");
        exit(1);
    }
    
    int ret = close(fd);
    if(ret == -1){
        perror("close error");
        exit(1);
    }else{
        printf("%d\n",ret);
    }
    
}
