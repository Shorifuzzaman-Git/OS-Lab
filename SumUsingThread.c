//Sum of N numbers

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int ans=0;
void* sum(void *arg){
    int x=*((int*)arg);
    for(int i=1;i<=x;i++){
        ans+=i;
    }
    printf("Ans = %d",ans);
    //pthread_exit(NULL);
}

int main(){
    int x;
    scanf("%d",&x);
    pthread_t t1;
    pthread_create(&t1,NULL,sum,&x);
    pthread_join(t1,NULL);
}