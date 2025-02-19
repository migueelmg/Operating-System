#pragma once
#include <string>
#include <iostream>

class Process {

public:
	int pid = 0;
	float arrival_time = 0;
	float burst_time = 0;
	int priority;
	string state;
	float remaining_time = 0;
	float waiting_time = 0;
	float turnaround_time = 0;
	int memory_required = 0;
	bool io_operations;

	Process() {
		pid += 1;
		priority = 1;
		state = "READY";
	}

	Process(int processPID, int processPriority, string stateOfProcess, bool io, int size) {
		pid = processPID;
		priority = processPriority;
		state = stateOfProcess;
		io_operations = io;
		memory_required = size;
	}

	void updateState(Process process, string newState) {
		process.setState(newState);
	}

	string getState() {
		return state;
	}

	void setState(string newState) {
		state = newState;
	}

	//method prints out process attributes
	void printAttributes() {
		cout << "Process ID: " << pid << endl;
		cout << "Process priority: " << priority << endl;
		cout << "Process state: " << state << endl;
		cout << "Process memory requirement: " << memory_required << "MB" << endl;
	}


};