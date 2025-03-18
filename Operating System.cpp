#include <iostream>
#include <string>
#include <vector>
#include "bootingSystem.h"
#include "process.h"
#include "createProcess.h"
#include "scheduling.h"  // Make sure to include scheduling.h

using namespace std;

int main() {
    bootingSystem();

    // user decides whether to start processes, or to shut down the system
    string input;
    cout << "To start initiating processes, enter 'start'. To shut down system, enter 'stop': ";
    cin >> input;

    // if user chooses to start, processes will be initialized and their attributes will be printed
    if (input == "start") {
        int countOfProcesses;
        cout << "How many processes are you creating? ";
        cin >> countOfProcesses;

        vector<Process> processes;  // Vector to store processes

        // Creates countOfProcesses processes
        for (int i = 0; i < countOfProcesses; i++) {
            int pid, arrival_time, burst_time, priority;
            cout << "Enter PID for Process " << i + 1 << ": ";
            cin >> pid;
            cout << "Enter Arrival Time for Process " << i + 1 << ": ";
            cin >> arrival_time;
            cout << "Enter Burst Time for Process " << i + 1 << ": ";
            cin >> burst_time;
            cout << "Enter Priority for Process " << i + 1 << ": ";
            cin >> priority;

            Process p(pid, priority, arrival_time, burst_time);
            p.state = "new";  // Set initial state to 'new'
            processes.push_back(p);
        }

        // Choose scheduling algorithm
        string algorithm;
        cout << "Choose scheduling algorithm (FCFS/SJF): ";
        cin >> algorithm;

        if (algorithm == "FCFS") {
            cout << "Executing FCFS Scheduling..." << endl;
            FCFS(processes);  // Call FCFS scheduler function
        }
        else if (algorithm == "SJF") {
            cout << "Executing SJF Scheduling..." << endl;
            SJF(processes);  // Call SJF scheduler function
        }
        else {
            cout << "Invalid algorithm choice. Please enter FCFS or SJF." << endl;
        }

    }
    // otherwise, system will shut down
    else if (input == "stop") {
        cout << "System shutting down..." << endl;
    }

    return 0;
}
