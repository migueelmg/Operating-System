#include <iostream>
#include <string>
#include "bootingSystem.h"
#include "process.h"
#include "createProcess.h"

int main()
{
    bootingSystem();

    //user decides whether to start processes, or to shut down the system
    string input;
    cout << "To start initiating processes, enter 'start'. To shut down system, enter 'stop'" << endl;
    cin >> input;

    //if user chooses to start, five processes will be initialized and their attributes will be printed
    if (input == "start") {
        int countOfProcesses;
        cout << "How many processes are you creating?" << endl;
        cin >> countOfProcesses;

        //creates countOfProcesses processes
        for (int i = 0; i < countOfProcesses; i++) {
            createProcess();
        }

    }
    //otherwise, system will shut down
    else if (input == "stop") {
        cout << "System shutting down..." << endl;
    }

    
    return 0;
}

