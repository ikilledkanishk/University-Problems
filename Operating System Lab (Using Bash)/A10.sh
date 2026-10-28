#a. Program to implement a semaphore and a program to show that two semaphores with the same key value cannot be created.
#Source Code:

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
int main()
{
    key_t key = 1234;
    int sem1, sem2;
    sem1 = semget(key, 1, IPC_CREAT | 0666);
    if (sem1 == -1)
    {
        perror("semget");
        return 1;
    }
    printf("Semaphore created successfully.\n");
    printf("Semaphore ID: %d\n", sem1);
    sem2 = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);
    if (sem2 == -1)
        printf("Another semaphore with the same key cannot be created.\n");
    else
        printf("Second semaphore created. ID: %d\n", sem2);
    semctl(sem1, 0, IPC_RMID);
    return 0;
}

#b. Program to find out the maximum number of semaphores that can be created.
#Source Code:

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#define MAX 100000
int main()
{
    int semid[MAX];
    int count = 0;
    key_t key;
    for (int i = 0; i < MAX; i++)
    {
        key = IPC_PRIVATE;
        semid[count] = semget(key, 1, IPC_CREAT | 0600);
        if (semid[count] == -1)
        {
            perror("semget");
            break;
        }
        count++;
    }
    printf("Maximum semaphore sets created by this program: %d\n", count);
    for (int i = 0; i < count; i++)
        semctl(semid[i], 0, IPC_RMID);
    printf("All semaphore sets created by this program have been removed.\n");
    return 0;
}
