// virtual_memory.cpp (optimized for demand paging)
#include "virtual_memory.h"
#include <iostream>
using namespace std;

// Global frame table to simulate physical memory frame allocation
bool frameTable[NUM_PHYSICAL_FRAMES] = { false }; // false = free, true = used

// Allocate a physical frame to a specific virtual page of a process
bool allocatePage(Process& process, int virtualPage) {
    if (virtualPage >= NUM_VIRTUAL_PAGES) return false;

    // Only allocate if not already valid
    if (process.pageTable[virtualPage].valid) return true;

    // Find a free frame
    for (int i = 0; i < NUM_PHYSICAL_FRAMES; ++i) {
        if (!frameTable[i]) {
            frameTable[i] = true;
            process.pageTable[virtualPage].valid = true;
            process.pageTable[virtualPage].frameNumber = i;
            cout << "Allocated frame " << i << " to virtual page " << virtualPage
                << " of process P" << process.pid << endl;
            return true;
        }
    }

    cout << "No free physical frames available for P" << process.pid << endl;
    return false;
}

// Translates a virtual address to a physical address for a process
int translateAddress(Process& process, int virtualAddress) {
    int pageNumber = virtualAddress / PAGE_SIZE;
    int offset = virtualAddress % PAGE_SIZE;

    if (pageNumber >= NUM_VIRTUAL_PAGES) {
        cerr << "Error: Virtual address out of bounds." << endl;
        return -1;
    }

    PageTableEntry& entry = process.pageTable[pageNumber];

    // Simulate on-demand page allocation
    if (!entry.valid) {
        cout << "Page fault: Virtual page " << pageNumber
            << " not in memory for P" << process.pid << ". Attempting to allocate..." << endl;
        if (!allocatePage(process, pageNumber)) return -1;
    }

    int physicalAddress = (entry.frameNumber * PAGE_SIZE) + offset;
    return physicalAddress;
}

// Print the page table for a process
void printPageTable(const Process& process) {
    cout << "\nPage Table for Process P" << process.pid << ":\n";
    cout << "Virtual Page\tValid\tFrame\n";
    for (int i = 0; i < NUM_VIRTUAL_PAGES; ++i) {
        const PageTableEntry& entry = process.pageTable[i];
        if (entry.valid) {
            cout << i << "\t\t" << entry.valid << "\t" << entry.frameNumber << endl;
        }
    }
    cout << endl;
}
