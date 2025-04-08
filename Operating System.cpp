#include <iostream>
#include <string>
#include <vector>
#include "bootingSystem.h"
#include "process.h"
#include "createProcess.h"
#include "scheduling.h"
#include "constants.h"
#include "virtual_memory.h" 

using namespace std;

int main() {
    bootingSystem();

    string input;
    cout << "To start initiating processes, enter 'start'. To shut down system, enter 'stop': ";
    cin >> input;

    if (input == "start") {
        int countOfProcesses;
        cout << "How many processes are you creating? ";
        cin >> countOfProcesses;

        vector<Process> processes;

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
            p.state = "new";
            processes.push_back(p);
        }

        string algorithm;
        cout << "Choose scheduling algorithm (FCFS/SJF): ";
        cin >> algorithm;

        if (algorithm == "FCFS") {
            cout << "Executing FCFS Scheduling..." << endl;
            FCFS(processes);
        }
        else if (algorithm == "SJF") {
            string type;
            cout << "Choose type (preemptive/non-preemptive): ";
            cin >> type;

            if (type == "preemptive") {
                cout << "Executing Preemptive SJF (SRTF) Scheduling..." << endl;
                SJF_Preemptive(processes);
            }
            else {
                cout << "Executing Non-Preemptive SJF Scheduling..." << endl;
                SJF_NonPreemptive(processes);
            }
        }
        else {
            cout << "Invalid algorithm choice. Please enter FCFS or SJF." << endl;
        }

    }
    else if (input == "stop") {
        cout << "System shutting down..." << endl;
    }

    return 0;
}
