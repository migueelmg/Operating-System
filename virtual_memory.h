#pragma once
#include "process.h" // Your Process class
#include "constants.h"

// Translates a virtual address to a physical address for a process
int translateAddress(Process& process, int virtualAddress);
