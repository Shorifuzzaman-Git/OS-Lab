//Race condition solve

#include <stdio.h>
#include <pthread.h>

int ans=0;
pthread_mutex_t lock;
void *sum(){
    for(int i=1;i<=1000000;i++){
        pthread_mutex_lock(&lock);
        ans++;
        pthread_mutex_unlock(&lock);
    }
    
}

int main(){
    pthread_t t1,t2;
    pthread_mutex_init(&lock,NULL);
    
    pthread_create(&t1,NULL,sum,NULL);
    pthread_create(&t2,NULL,sum,NULL);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    pthread_mutex_destroy(&lock);
    
    printf("%d",ans);
}