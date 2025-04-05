#pragma once
#include "constants.h"
#include <string>
#include <iostream>
using namespace std;

// Page Table Entry for virtual memory
struct PageTableEntry {
    bool valid = false;        // Is this page loaded into physical memory?
    int frameNumber = -1;      // Frame number in physical memory
    bool dirty = false;        // Optional for write-back (not used here)
};

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
    int completion_time;

    // Page table for virtual memory (fixed-size array)
    PageTableEntry pageTable[NUM_VIRTUAL_PAGES];

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

        // Initialize the page table
        for (int i = 0; i < NUM_PHYSICAL_FRAMES && i < NUM_VIRTUAL_PAGES; ++i) {
            pageTable[i].valid = true;
            pageTable[i].frameNumber = i;
        }

        for (int i = NUM_PHYSICAL_FRAMES; i < NUM_VIRTUAL_PAGES; ++i) {
            pageTable[i].valid = false;
            pageTable[i].frameNumber = -1;
        }
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
