#pragma once
#include <string>
#include <iostream>
using namespace std;

class Process {

public:
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    string state;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int io_operations;
    int completion_time;  // Added completion time

    // Constructor for when user or system specifies attributes
    Process(int pid, int priority, int arrival_time, int burst_time) {
        this->pid = pid;
        this->priority = priority;
        this->arrival_time = arrival_time;
        this->burst_time = burst_time;
        this->remaining_time = burst_time; // Initialize remaining time to burst time
        this->state = "not started";       // Default state
        this->waiting_time = 0;
        this->turnaround_time = 0;
        this->io_operations = 0;
        this->completion_time = 0;  // Initialize completion time
    }

    // Update process state
    void updateState(string newState) {
        state = newState;
    }

    // Calculate turnaround time
    void calculateTurnaroundTime() {
        turnaround_time = completion_time - arrival_time;
    }

    // Calculate waiting time
    void calculateWaitingTime() {
        waiting_time = turnaround_time - burst_time;
    }

    // Print process attributes
    void printAttributes() {
        cout << "Process ID: " << pid << endl;
        cout << "Arrival Time: " << arrival_time << endl;
        cout << "Burst Time: " << burst_time << endl;
        cout << "Priority: " << priority << endl;
        cout << "State: " << state << endl;
        cout << "Completion Time: " << completion_time << endl;
        cout << "Turnaround Time: " << turnaround_time << endl;
        cout << "Waiting Time: " << waiting_time << endl;
        cout << endl;
    }

    // Getter and setter functions
    int getCompletionTime() { return completion_time; }
    void setCompletionTime(int time) { completion_time = time; }

    int getRemainingTime() { return remaining_time; }
    void setRemainingTime(int time) { remaining_time = time; }

    int getWaitingTime() { return waiting_time; }
    void setWaitingTime(int time) { waiting_time = time; }

    int getTurnaroundTime() { return turnaround_time; }
    void setTurnaroundTime(int time) { turnaround_time = time; }
};
