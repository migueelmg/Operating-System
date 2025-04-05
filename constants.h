#pragma once

// Constants for memory system configuration

// Page size in bytes (4KB)
const int PAGE_SIZE = 4096;

// Total virtual memory size (1MB)
const int VIRTUAL_MEMORY_SIZE = 1 << 20;

// Total physical memory size (256KB)
const int PHYSICAL_MEMORY_SIZE = 1 << 18;

// Number of virtual pages per process
const int NUM_VIRTUAL_PAGES = VIRTUAL_MEMORY_SIZE / PAGE_SIZE;

// Number of physical frames available in the system
const int NUM_PHYSICAL_FRAMES = PHYSICAL_MEMORY_SIZE / PAGE_SIZE;
