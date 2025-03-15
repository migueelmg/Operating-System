#pragma once
#include <string>
#include <iostream>

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
	int memory_required;
	int io_operations;

	//constructor for when user or system specifies attributes
	Process(int pid, int priority, int arrival_time, int burst_time) {
		this->pid = pid;
		this->priority = priority;
		this->arrival_time = arrival_time;
		this->burst_time = burst_time;
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

	int getArrivalTime() {
		return arrival_time;
	}

	void setArrivalTime(float arrival_time) {
		this->arrival_time = arrival_time;
	}

	int getBurstTime() {
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

	int getRemainingTime() {
		return remaining_time;
	}

	void setRemainingTime(float remaining_time) {
		this->remaining_time = remaining_time;
	}

	int getWaitingTime() {
		return waiting_time;
	}

	void setWaitingTime(float waiting_time) {
		this->waiting_time = waiting_time;
	}

	int getTurnAroundTime() {
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

	int getIO_Operations() {
		return io_operations;
	}

	void setIO_Operations(bool io_operations) {
		this->io_operations = io_operations;
	}

};