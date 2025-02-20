#pragma once
#include <string>
#include <iostream>

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

	//constructor for basic process
	Process() {
		pid = 1;
		priority = 1;
		state = "READY";
	}

	//constructor for when user or system specifies attributes
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

	//method prints out process attributes
	void printAttributes() {
		cout << "Process ID: " << pid << endl;
		cout << "Process priority: " << priority << endl;
		cout << "Process state: " << state << endl;
		cout << "Process memory requirement: " << memory_required << "MB" << endl;
	}

	//getters and setters for process class
	string getState() {
		return state;
	}

	void setState(string state) {
		this->state = state;
	}

	int getPID() {
		return pid;
	}

	void setPID(int pid) {
		this->pid = pid;
	}

	float getArrivalTime() {
		return arrival_time;
	}

	void setArrivalTime(float arrival_time) {
		this->arrival_time = arrival_time;
	}

	float getBurstTime() {
		return burst_time;
	}

	void setBurstTime(float burst_time) {
		this->burst_time = burst_time;
	}

	int getPriority() {
		return priority;
	}

	void setPriority(int priority) {
		this->priority = priority;
	}

	float getRemainingTime() {
		return remaining_time;
	}

	void setRemainingTime(float remaining_time) {
		this->remaining_time = remaining_time;
	}

	float getWaitingTime() {
		return waiting_time;
	}

	void setWaitingTime(float waiting_time) {
		this->waiting_time = waiting_time;
	}

	float getTurnAroundTime() {
		return turnaround_time;
	}

	void setTurnAroundTime(float turnaround_time) {
		this->turnaround_time = turnaround_time;
	}

	int getMemoryRequired() {
		return memory_required;
	}

	void setMemoryRequired(int memory_required) {
		this->memory_required = memory_required;
	}

	bool getIO_Operations() {
		return io_operations;
	}

	void setIO_Operations(bool io_operations) {
		this->io_operations = io_operations;
	}

};