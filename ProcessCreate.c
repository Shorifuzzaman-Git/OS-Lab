#include <stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>


int main()
{
    pid_t a;
    a=fork();
    if(a<0){
        printf("Process is not created.");
    }
    else if(a==0){
        printf("Process is created.\n");
    }
    else{
        wait(NULL);
        printf("Parent process.\n");
    }

    return 0;
}