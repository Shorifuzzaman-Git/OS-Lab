//SJF CPU scheduling algorithm for preemptive 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int remainingTime;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter arrival time and burst time for process :\n";
    for (int i = 0; i < n; ++i) {
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].pid = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }

    int completed = 0, currentTime = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    while (completed < n) {
        int idx = -1;
        int minRT = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                if (processes[i].remainingTime < minRT) {
                    minRT = processes[i].remainingTime;
                    idx = i;
                }
                else if (processes[i].remainingTime == minRT) {
                    if (processes[i].arrivalTime < processes[idx].arrivalTime)
                        idx = i;
                }
            }
        }

        if (idx != -1) {
            processes[idx].remainingTime--;
            currentTime++;

            if (processes[idx].remainingTime == 0) {
                completed++;
                processes[idx].completionTime = currentTime;
                processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
                processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;

                totalWaitingTime += processes[idx].waitingTime;
                totalTurnaroundTime += processes[idx].turnaroundTime;
            }
        } else {
            // CPU is idle
            currentTime++;
        }
    }

    cout<<"PID\tArrival\tBurst\tCompletion\tTurnArround\tWaiting\t \n";
    for(int i=0;i<n;i++){
        cout<<processes[i].pid<<"\t"<<processes[i].arrivalTime<<"\t"<<
        processes[i].burstTime<<"\t"<<processes[i].completionTime<<"\t\t"<<
        processes[i].turnaroundTime<<"\t\t"<<processes[i].waitingTime<<endl;
    }

    cout << "\nAverage Waiting Time: " << totalWaitingTime / n;
    cout << "Average Turnaround Time: " << totalTurnaroundTime / n << endl;

    return 0;
}

// 2 6
// 1 3
// 4 2
// 0 5
// 6 4
