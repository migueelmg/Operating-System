#include "scheduling.h"
#include <algorithm>

// FCFS Scheduling Algorithm
void FCFS(std::vector<Process>& processes) {
    // Sort processes by arrival time
    std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrival_time < b.arrival_time;
        });

    int currentTime = 0;  // To track the time
    for (auto& process : processes) {
        // Initialize remaining time
        process.remaining_time = process.burst_time;

        // Update the waiting time before the state change
        if (currentTime < process.arrival_time) {
            currentTime = process.arrival_time; // If process arrives after current time, adjust time
        }

        process.waiting_time = currentTime - process.arrival_time;
        process.turnaround_time = process.waiting_time + process.burst_time;

        process.state = "running";  // Mark process as running
        cout << "Time: " << currentTime << "s" << endl;
        cout << "Process ID: " << process.pid << " | Remaining Time: " << process.remaining_time << endl;
        cout << "Priority: " << process.priority << " | State: " << process.state << endl;

        // Update the current time with burst time (completion)
        currentTime += process.burst_time;

        process.completion_time = currentTime;

        // Mark process as finished after its burst time completes
        process.state = "finished";
        cout << "Process ID: " << process.pid << " Finished!" << endl;
        cout << "-------------------------------------------------" << endl;
    }

    // Optionally, calculate and print average times
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (const auto& process : processes) {
        totalWaitingTime += process.waiting_time;
        totalTurnaroundTime += process.turnaround_time;
    }
    cout << "Average Waiting Time: " << (float)totalWaitingTime / processes.size() << endl;
    cout << "Average Turnaround Time: " << (float)totalTurnaroundTime / processes.size() << endl;
}




void SJF(std::vector<Process>& processes) {
    // Sort processes by arrival time first, then by burst time
    std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        if (a.arrival_time == b.arrival_time) {
            return a.burst_time < b.burst_time; // If arrival times are the same, shortest burst time first
        }
        return a.arrival_time < b.arrival_time;
        });

    int currentTime = 0;  // Track the current time
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (auto& process : processes) {
        // If the process arrives after current time, jump to the process's arrival time
        if (currentTime < process.arrival_time) {
            currentTime = process.arrival_time;
        }

        // Calculate waiting time (current time - arrival time)
        process.waiting_time = currentTime - process.arrival_time;

        // Calculate turnaround time (waiting time + burst time)
        process.turnaround_time = process.waiting_time + process.burst_time;

        // Update current time (finish time)
        currentTime += process.burst_time;

        // Print the process execution details
        cout << "Time: " << currentTime << "s" << endl;
        cout << "Process ID: " << process.pid << " | State: Running" << endl;
        cout << "Burst Time: " << process.burst_time << " | Waiting Time: " << process.waiting_time << endl;
        cout << "Turnaround Time: " << process.turnaround_time << endl;
        cout << "Process ID: " << process.pid << " Finished!" << endl;
        cout << "-------------------------------------------------" << endl;

        // Add to totals
        totalWaitingTime += process.waiting_time;
        totalTurnaroundTime += process.turnaround_time;
    }

    // Calculate and display average waiting time and turnaround time
    float avgWaitingTime = totalWaitingTime / processes.size();
    float avgTurnaroundTime = totalTurnaroundTime / processes.size();

    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
}















 