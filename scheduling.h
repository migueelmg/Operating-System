#ifndef SCHEDULING_H
#define SCHEDULING_H

#include <vector>
#include "process.h"

// First-Come, First-Served (FCFS) Scheduling
void FCFS(std::vector<Process>& processes);

// Shortest Job First (Non-Preemptive) Scheduling
void SJF_NonPreemptive(std::vector<Process>& processes);

// Shortest Job First (Preemptive / SRTF) Scheduling
void SJF_Preemptive(std::vector<Process>& processes);

#endif // SCHEDULING_H
