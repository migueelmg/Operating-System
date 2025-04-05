// virtual_memory.cpp
#include "virtual_memory.h"
#include <iostream>
using namespace std;

// Translates a virtual address to a physical address for a process
int translateAddress(Process& process, int virtualAddress) {
    int pageNumber = virtualAddress / PAGE_SIZE;
    int offset = virtualAddress % PAGE_SIZE;

    // Check if page number is out of range
    if (pageNumber >= NUM_VIRTUAL_PAGES) {
        cerr << "Error: Virtual address out of bounds." << endl;
        return -1;
    }

    PageTableEntry& entry = process.pageTable[pageNumber];

    // Check if the page is valid (i.e., loaded into memory)
    if (!entry.valid) {
        cerr << "Page fault: Virtual page " << pageNumber << " not in physical memory." << endl;
        return -1;
    }

    int physicalAddress = (entry.frameNumber * PAGE_SIZE) + offset;
    return physicalAddress;
}
