#include <iostream>
#include <string>
#include "bootingSystem.h"
#include "process.h"

int main()
{
    bootingSystem();
    string input;
    cout << "To start initiating processes, enter 'start'. To shut down system, enter 'shut down'" << endl;
    cin >> input;

    if (input == "start") {
        Process process1(0,1,"READY",true,3);
        Process process2(1, 1, "READY", true, 4);
        Process process3(2, 1, "READY", true, 2);
        Process process4(3, 1, "READY", true, 5);
        Process process5(4, 1, "READY", true, 1);

        process1.printAttributes();
        process2.printAttributes();
        process3.printAttributes();
        process4.printAttributes();
        process5.printAttributes();
    }
    else if (input == "shut down") {
        cout << "System shutting down..." << endl;
    }

    
    return 0;
}

