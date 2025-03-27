#include "scheduling.h"
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Helper to print ready queue
void printReadyQueue(const vector<Process*>& readyQueue) {
    cout << "Ready Queue: [";
    for (const auto& p : readyQueue) {
        cout << "P" << p->pid << " ";
    }
    cout << "]\n";
}

// FCFS Scheduling (non-preemptive)
void FCFS(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrival_time < b.arrival_time;
        });

    int currentTime = 0;
    vector<Process*> readyQueue;
    int completed = 0;
    size_t index = 0;

    cout << "\n=== FCFS Scheduling ===\n";

    while (completed < processes.size()) {
        while (index < processes.size() && processes[index].arrival_time <= currentTime) {
            cout << "Time " << currentTime << ": P" << processes[index].pid << " has arrived and moved to Ready Queue.\n";
            readyQueue.push_back(&processes[index]);
            index++;
        }

        printReadyQueue(readyQueue);

        if (!readyQueue.empty()) {
            Process* p = readyQueue.front();
            readyQueue.erase(readyQueue.begin());

            p->state = "running";
            cout << "Time " << currentTime << ": P" << p->pid << " starts running.\n";

            currentTime += p->burst_time;
            p->completion_time = currentTime;
            p->calculateTurnaroundTime();
            p->calculateWaitingTime();
            p->state = "finished";
            cout << "Time " << currentTime << ": P" << p->pid << " finishes.\n";
            completed++;
        }
        else {
            cout << "Time " << currentTime << ": CPU is idle.\n";
            currentTime++;
        }
    }

    float totalWaiting = 0, totalTurnaround = 0;
    for (const auto& p : processes) {
        totalWaiting += p.waiting_time;
        totalTurnaround += p.turnaround_time;
    }

    cout << "\nAverage Waiting Time: " << totalWaiting / processes.size() << endl;
    cout << "Average Turnaround Time: " << totalTurnaround / processes.size() << endl;
}

// SJF Non-Preemptive Scheduling
void SJF_NonPreemptive(vector<Process>& processes) {
    int currentTime = 0;
    int completed = 0;
    vector<Process*> readyQueue;
    size_t index = 0;

    cout << "\n=== SJF (Non-Preemptive) Scheduling ===\n";

    while (completed < processes.size()) {
        while (index < processes.size() && processes[index].arrival_time <= currentTime) {
            cout << "Time " << currentTime << ": P" << processes[index].pid << " has arrived and moved to Ready Queue.\n";
            readyQueue.push_back(&processes[index]);
            index++;
        }

        printReadyQueue(readyQueue);

        if (!readyQueue.empty()) {
            auto it = min_element(readyQueue.begin(), readyQueue.end(), [](Process* a, Process* b) {
                return a->burst_time < b->burst_time;
                });

            Process* p = *it;
            readyQueue.erase(it);

            cout << "Time " << currentTime << ": P" << p->pid << " starts running.\n";

            p->state = "running";
            currentTime += p->burst_time;
            p->completion_time = currentTime;
            p->calculateTurnaroundTime();
            p->calculateWaitingTime();
            p->state = "finished";

            cout << "Time " << currentTime << ": P" << p->pid << " finishes.\n";
            completed++;
        }
        else {
            cout << "Time " << currentTime << ": CPU is idle.\n";
            currentTime++;
        }
    }

    float totalWaiting = 0, totalTurnaround = 0;
    for (const auto& p : processes) {
        totalWaiting += p.waiting_time;
        totalTurnaround += p.turnaround_time;
    }

    cout << "\nAverage Waiting Time: " << totalWaiting / processes.size() << endl;
    cout << "Average Turnaround Time: " << totalTurnaround / processes.size() << endl;
}

// SJF Preemptive Scheduling (Shortest Remaining Time First)
void SJF_Preemptive(vector<Process>& processes) {
    int currentTime = 0;
    int completed = 0;
    size_t n = processes.size();
    Process* current = nullptr;
    vector<int> arrived(n, 0);

    cout << "\n=== SJF (Preemptive - SRTF) Scheduling ===\n";

    while (completed < n) {
        vector<Process*> readyQueue;

        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time == currentTime && !arrived[i]) {
                cout << "Time " << currentTime << ": P" << processes[i].pid << " has arrived and moved to Ready Queue.\n";
                arrived[i] = 1;
            }
            if (arrived[i] && processes[i].state != "finished") {
                readyQueue.push_back(&processes[i]);
            }
        }

        printReadyQueue(readyQueue);

        if (!readyQueue.empty()) {
            auto it = min_element(readyQueue.begin(), readyQueue.end(), [](Process* a, Process* b) {
                return a->remaining_time < b->remaining_time;
                });

            Process* selected = *it;

            if (current != selected) {
                if (current != nullptr && current->state == "running") {
                    cout << "Time " << currentTime << ": P" << current->pid << " is preempted by P" << selected->pid << ".\n";
                }
                cout << "Time " << currentTime << ": P" << selected->pid << " starts/resumes running.\n";
                current = selected;
            }
            else {
                cout << "Time " << currentTime << ": P" << current->pid << " continues running.\n";
            }

            current->state = "running";
            current->remaining_time--;
            currentTime++;

            if (current->remaining_time == 0) {
                current->completion_time = currentTime;
                current->calculateTurnaroundTime();
                current->calculateWaitingTime();
                current->state = "finished";
                cout << "Time " << currentTime << ": P" << current->pid << " finishes.\n";
                completed++;
                current = nullptr;
            }
        }
        else {
            cout << "Time " << currentTime << ": CPU is idle.\n";
            currentTime++;
        }
    }

    float totalWaiting = 0, totalTurnaround = 0;
    for (const auto& p : processes) {
        totalWaiting += p.waiting_time;
        totalTurnaround += p.turnaround_time;
    }

    cout << "\nAverage Waiting Time: " << totalWaiting / processes.size() << endl;
    cout << "Average Turnaround Time: " << totalTurnaround / processes.size() << endl;
}
