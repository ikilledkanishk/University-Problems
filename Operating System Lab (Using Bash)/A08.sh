#Programming Signal: Programs to run user-defined code for a signal and reset them to the default code.
#Source Code:

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
void inthandler(int sig_no); 
int main()
{
    int pid;
    if((pid=fork()) < 0)
    {
        perror("child process could not be created");
        exit(1);
    }
    if(pid==0)
    { 
        printf("In child pid: %d; process id: %d\n\n",pid,getpid());
        signal(SIGINT,inthandler); 
        for(;;);
    }
    if(pid>0)
    {
        //sleep(2);
        printf("In parent pid: %d; process id: %d\n\n",pid,getpid());
        printf("Sending SIGINT signal\n");
        kill(pid,SIGINT);
        sleep(2);
        printf("sending SIGSTOP signal\n");
        kill(pid,SIGSTOP);
    }
    return 0;
}
void inthandler(int sig_no)
{
    signal(SIGINT,inthandler);
    printf("interrupt signal handled by child\n\n");
}
