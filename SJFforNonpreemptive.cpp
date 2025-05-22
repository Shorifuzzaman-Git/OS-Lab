//SJF CPU scheduling algorithm for non-preemptive 

#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    bool isCompleted = false;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    // Input: arrival and burst time (in any order)
    cout << "Enter arrival time and burst time for process :\n";
    for (int i = 0; i < n; ++i) {
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].pid = i + 1;
    }

    int currentTime = 0, completed = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    while (completed < n) {
        int idx = -1;
        int minBurst = INT_MAX;

        // Find process with minimum burst among arrived and not completed
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrivalTime <= currentTime && !processes[i].isCompleted) {
                if (processes[i].burstTime < minBurst) { //if burst time less than 
                    minBurst = processes[i].burstTime;
                    idx = i;
                } else if (processes[i].burstTime == minBurst) { //if burst time equal than compare arrival time
                    if (processes[i].arrivalTime < processes[idx].arrivalTime) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            //processes[idx].startTime = currentTime;
            processes[idx].completionTime = currentTime + processes[idx].burstTime;
            processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
            processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;

            totalWaitingTime += processes[idx].waitingTime;
            totalTurnaroundTime += processes[idx].turnaroundTime;

            currentTime = processes[idx].completionTime;
            processes[idx].isCompleted = true;
            completed++;
        } else {
            // If no process has arrived yet, increment time
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
    cout << "\nAverage Turnaround Time: " << totalTurnaroundTime / n << endl;

    return 0;
}

// 4 5
// 0 2
// 1 5
// 6 7
// 2 3
