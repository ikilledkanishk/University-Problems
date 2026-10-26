'''Programming: Process 
a. Simple C programs related to the concepts of: 
• Background Process 
• Parent Process 
• Child Process 
• Zombie Process'''
#Source Code:

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t pid;
    printf("Parent Process ID: %d\n", getpid());
    pid = fork();
    if (pid < 0)
    {
        printf("Process creation failed.\n");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child Process ID: %d\n", getpid());
        printf("Child's Parent Process ID: %d\n", getppid());
        printf("Child process running in background.\n");
        exit(0);
    }
    else
    {
        printf("Parent created Child with PID: %d\n", pid);
        printf("Parent sleeping to demonstrate zombie process.\n");

        sleep(10);

        wait(NULL);
        printf("Child process reaped by parent.\n");
    }

    return 0;
}

'''b. Simple C programs related to the concepts of: 


• Orphan Process 
• Sleeping Process 
• Running Process'''
#Source Code:

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Process creation failed.\n");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child process started. PID: %d\n", getpid());
        printf("Child is sleeping for 5 seconds.\n");
        sleep(5);
        printf("Child is now running again.\n");
        printf("Child's new parent PID: %d\n", getppid());
        printf("Child process completed.\n");
    }
    else
    {
        printf("Parent process PID: %d\n", getpid());
        printf("Parent is exiting.\n");
        exit(0);
    }
    return 0;
}
