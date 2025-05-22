//FCFS scheduling algorithm without arrival time in C program

#include<stdio.h>

int main(){
    int n;//number of precess
    printf("Enter number of process : ");
    scanf("%d",&n);

    int bt[n];
    printf("Enter burst time : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    int ct[n],wt[n],tat[n];
    ct[0]=bt[0];
    wt[0]=0;
    tat[0]=bt[0]+wt[0];
    int twt=wt[0];
    int ttat=tat[0];
    for(int i=1;i<n;i++){
        ct[i]=ct[i-1]+bt[i];
        wt[i]=ct[i-1];
        twt+=wt[i];
        tat[i]=bt[i]+wt[i];
        ttat+=tat[i];
    }
    printf("P.ID \t BT \t CT \t WT \t TAT \n");
    for(int i=0;i<n;i++){
        printf("%d\t %d\t %d\t %d\t %d\n",i+1,bt[i],ct[i],wt[i],tat[i]);
    }
    float awt=twt/n;
    float atat=ttat/n;
    printf("Average waiting time : %f\n",awt);
    printf("Average tern arround time : %f\n",atat);
}