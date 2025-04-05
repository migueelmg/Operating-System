#include <iostream>
#include <string>
#include <vector>
#include "bootingSystem.h"
#include "process.h"
#include "createProcess.h"
#include "scheduling.h"
#include "constants.h"
#include "virtual_memory.h" // ? Added for address translation

using namespace std;

int main() {
    bootingSystem();

    // Prompt user to start or shut down
    string input;
    cout << "To start initiating processes, enter 'start'. To shut down system, enter 'stop': ";
    cin >> input;

    if (input == "start") {
        int countOfProcesses;
        cout << "How many processes are you creating? ";
        cin >> countOfProcesses;

        vector<Process> processes;

        // Gather process data from user
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

            // Create and initialize process
            Process p(pid, priority, arrival_time, burst_time);
            p.state = "new";

            // ? Virtual memory test: try translating a sample virtual address
            int testVirtualAddr = 8192; // Page 2
            int translated = translateAddress(p, testVirtualAddr);

            if (translated != -1) {
                cout << "Virtual address " << testVirtualAddr
                    << " translated to physical address "
                    << translated << " for PID " << p.pid << endl;
            }
            else {
                cout << "Virtual address " << testVirtualAddr
                    << " could not be translated for PID " << p.pid << endl;
            }

            processes.push_back(p);
        }

        // Select scheduling algorithm
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
