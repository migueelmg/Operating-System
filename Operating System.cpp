#include <iostream>
#include <string>
#include "auth.h"
#include "bootingSystem.h"

int main()
{
    string username;
    string password;
    cout << "Enter a Username and Password: " << endl;
    cin >> username;
    cin >> password;
    cout << authenticateUser(username, password) << endl;
    bootingSystem(username);
    return 0;
}

