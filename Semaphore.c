//Semaphore

#include <stdio.h>
#include <pthread.h>
#include<unistd.h>
#include<semaphore.h>

sem_t Semaphore;

void* func(void* arg){
    int x=((int)arg);
    printf("Hello from thread %d\n",x);
}

int main() {
    pthread_t t[5];
    sem_init(&Semaphore,0,1);
    
    for(int i=1;i<=5;i++){
        pthread_create(&t[i], NULL, func, &i);
        
        pthread_join(t[i], NULL);
    }
    
    sem_destroy(&Semaphore);
    return 0;
}