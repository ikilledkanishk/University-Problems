#Multithreaded Programming: Program to create two threads using the pthread library, performing different functions. Take one string as user input; one thread will show the string's length, and the other will show the string.
#Source Code:
  
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
void* func1(void* arg) 
{ 
    // detach the current thread 
	// pthread_detach(pthread_self());
    // from the calling thread 
    int len = strlen((char *)arg) ;
    printf("\nInside the thread1\n"); 
    printf("\nLength = %d",len);
    // exit the current thread 
    pthread_exit(NULL); 
} 
void* func2(void *arg)
{ 
    char *s1 = (char *)arg;
    printf("Inside the thread2\n"); 
    printf("\nUpper case = %s",s1);
    // exit the current thread 
    pthread_exit(NULL); 
} 
int main() 
{ 
    pthread_t ptid1, ptid2; 
    // Creating a new thread 
    char *s = "Hello World";
    pthread_create(&ptid1, NULL, &func1, (void *)s); 
    pthread_create(&ptid2, NULL, &func2, (void *)s); 
    printf("\nThis line may be printed"
           " before thread terminates\n"); 
    // The following line terminates 
    // the thread manually 
    // pthread_cancel(ptid1); 
    // Compare the two threads created 
    // if(pthread_equal(ptid1, ptid2)) 
    //     printf("Threads are equal\n"); 
    // else
    //     printf("Threads are not equal\n"); 
    // Waiting for the created thread to terminate 
    pthread_join(ptid1, NULL); 
    pthread_join(ptid2, NULL); 
    printf("This line will be printed"
          " after thread ends\n"); 
    // pthread_exit(NULL); 
    return 0;
}
