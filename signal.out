#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>


int main(int argc, char *argv[])
{
    int fd[2];
    //fd[0] to read
    //fd[1] to write
    if (pipe(fd) == -1) {
        printf("The pipe has an error occured.\n");
        return 1;
    }
    
    int id = fork();
    if (id == -1) {
        printf("Fork has an error occured.\n");
        return 4;
    }
    
    if (id == 0) {
        close(fd[1]);
        int y;
        if (read(fd[0], &y, sizeof(int)) == -1) {
            printf("The pipe has an error occured, cannot read from the pipe. \n");
            return 3;
        }
         close(fd[0]);
        
    }
    
    else {
        printf("This is child process.\n");
        close(fd[0]);
        int x;
        printf("This is parent process, enter a number: ");
        scanf("%d", &x);
        if (write(fd[1], &x, sizeof(int)) == -1) {
            printf("The pipe has an error occured, cannot write to the pipe.\n");
            return 2;
        }
        close(fd[1]);
    }
    return 0;
}