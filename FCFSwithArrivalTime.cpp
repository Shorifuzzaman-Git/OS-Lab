//FCFC scheduling algorithm with arrival time

#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

bool compare(Process a, Process b) {
    return a.arrivalTime < b.arrivalTime;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter arrival time and burst time for process :\n";
    for (int i = 0; i < n; ++i) {
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].pid = i + 1;
    }

    // Sort based on arrival time
    sort(processes.begin(), processes.end(), compare);

    int currentTime = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < n; ++i) {
        // If CPU is idle
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime=processes[i].turnaroundTime-processes[i].burstTime;

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;

        currentTime = processes[i].completionTime;
    }

    cout << "PID\t Arrival\t Burst\t Complete\t Turnaround\t Waiting\n";
    for (auto p : processes) {
        cout << p.pid << "\t" << p.arrivalTime << "\t\t" 
            << p.burstTime << "\t"<< p.completionTime << "\t\t"
            << p.turnaroundTime << "\t\t" << p.waitingTime << "\n";
    }

    cout << "Average Waiting Time: " << totalWaitingTime / n<<endl;;
    cout << "Average Turnaround Time: " << totalTurnaroundTime / n << endl;

}

// 3 1
// 4 5
// 0 2
// 3 7
// 5 5
