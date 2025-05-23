//Race condition

#include <stdio.h>
#include <pthread.h>

int ans=0;
void *sum(){
    for(int i=0;i<1000000;i++){
        ans++;
    }
}

int main(){
    pthread_t t1,t2;

    pthread_create(&t1,NULL,sum,NULL);
    pthread_create(&t2,NULL,sum,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("%d",ans);
}
//expected output is 2000000 but output is another number