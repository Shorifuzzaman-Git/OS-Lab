//thread create

#include <stdio.h>
#include<unistd.h>
#include<pthread.h>

void* func(){
    printf("Hi\n");
}

int main()
{
    pthread_t t1;
    pthread_create(&t1,NULL,func,NULL);
    pthread_join(t1,NULL);

    return 0;
}