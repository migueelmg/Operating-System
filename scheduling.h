#ifndef SCHEDULING_H
#define SCHEDULING_H

#include <vector>
#include <iostream>
#include "Process.h"

using namespace std;

// Function to execute FCFS Scheduling
void FCFS(vector<Process>& processes);

// Function to execute SJF Scheduling
void SJF(vector<Process>& processes);

#endif // SCHEDULING_H
