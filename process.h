#pragma once
#include <string>

class Process {

public:
	int pid;
	float arrival_time;
	float burst_time;
	int priority;
	string state;
	float remaining_time;
	float waiting_time;
	float turnaround_time;
	int memory_required;
	bool io_operations;

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


};