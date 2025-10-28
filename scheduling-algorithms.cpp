#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    string id;
    int arrival, burst, completion, turnaround;
};

// First-Come First-Serve
void FCFS(vector<Process> procs) {
    cout << "\n=== FCFS Scheduling ===\n";
    int time = 0;
    for (auto &p : procs) {
        if (time < p.arrival) time = p.arrival;
        time += p.burst;
        p.completion = time;
        p.turnaround = p.completion - p.arrival;
    }

    cout << "PID\tAT\tBT\tCT\tTAT\n";
    for (auto &p : procs)
        cout << p.id << "\t" << p.arrival << "\t" << p.burst
             << "\t" << p.completion << "\t" << p.turnaround << "\n";
}

// Shortest Job First (non-preemptive)
void SJF(vector<Process> procs) {
    cout << "\n=== SJF Scheduling ===\n";
    int n = procs.size();
    int time = 0, completed = 0;
    vector<bool> done(n, false);

    while (completed < n) {
        int idx = -1, minBT = 1e9;
        for (int i = 0; i < n; i++) {
            if (!done[i] && procs[i].arrival <= time && procs[i].burst < minBT) {
                minBT = procs[i].burst;
                idx = i;
            }
        }
        if (idx == -1) { time++; continue; }

        time += procs[idx].burst;
        procs[idx].completion = time;
        procs[idx].turnaround = procs[idx].completion - procs[idx].arrival;
        done[idx] = true;
        completed++;
    }

    cout << "PID\tAT\tBT\tCT\tTAT\n";
    for (auto &p : procs)
        cout << p.id << "\t" << p.arrival << "\t" << p.burst
             << "\t" << p.completion << "\t" << p.turnaround << "\n";
}

int main() {
    vector<Process> processes = {
        {"P1", 0, 3}, {"P2", 2, 2}, {"P3", 4, 4}, {"P4", 5, 3}, {"P5", 6, 5}
    };

    FCFS(processes);
    SJF(processes);
    return 0;
}
