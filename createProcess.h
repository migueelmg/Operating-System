#pragma once
#include "process.h"

void createProcess() {
    //user sets process info
    int processID;
    cout << "Enter Process ID: " << endl;
    cin >> processID;

    int arrivalTime;
    cout << "Enter arrival time: " << endl;
    cin >> arrivalTime;

    int burstTime;
    cout << "Enter burst time: " << endl;
    cin >> burstTime;

    int priority;
    cout << "Enter process priority: (1,2 or 3)" << endl;
    cin >> priority;

    //error check priority
    while (priority != 1 && priority != 2 && priority != 3) {
        cout << "Incorrect priority input. Re-enter priority integer." << endl;
        cin >> priority;
    }

    Process(processID, priority, arrivalTime, burstTime);
};