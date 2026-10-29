#a. A program for one-way communication between two processes.
#Source Code:

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main()
{
    int fd[2];
    char message[] = "Hello from parent process";
    char buffer[100];
    pipe(fd);
    if (fork() == 0)
    {
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    }
    else
    {
        close(fd[0]);
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}


#b. Program for two-way communications between two processes. 
#Source Code:

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main()
{
    int p1[2], p2[2];
    char buffer[100];
    pipe(p1);
    pipe(p2);
    if (fork() == 0)
    {
        close(p1[1]);
        close(p2[0]);
        read(p1[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        char reply[] = "Hello from child";
        write(p2[1], reply, strlen(reply) + 1);
        close(p1[0]);
        close(p2[1]);
    }
    else
    {
        close(p1[0]);
        close(p2[1]);
        char message[] = "Hello from parent";
        write(p1[1], message, strlen(message) + 1);
        read(p2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
        close(p1[1]);
        close(p2[0]);
        wait(NULL);
    }
    return 0;
}


#d. Named pipe execution
