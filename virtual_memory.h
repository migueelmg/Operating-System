#pragma once
#include "process.h"
#include "constants.h"

// Translates a virtual address to a physical address for a process
int translateAddress(Process& process, int virtualAddress);

// Allocates a physical frame to a virtual page
bool allocatePage(Process& process, int virtualPage);

void printPageTable(const Process& process);  
