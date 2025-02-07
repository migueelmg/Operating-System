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
    if (authenticateUser(username, password) == "Login successful!") {
        cout << authenticateUser(username, password) << endl;
        bootingSystem(username);
    }
    else {
        cout << authenticateUser(username, password) << endl;
    }
 
    
    return 0;
}

