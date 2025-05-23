//Thread array

#include <stdio.h>
#include <pthread.h>

int ans=0;
void *sum(){
    ans++;
}

int main(){
    pthread_t t[5];

    for(int i=0;i<5;i++){
        pthread_create(&t[i],NULL,sum,NULL);
        printf("Start\n");
        pthread_join(t[i],NULL);
        printf("Finished\n");
    }
    
    printf("%d",ans);
}