#pragma once
#include <iostream>
#include <string>
using namespace std;

void authenticateUser() {
	string username;
	string password;
	cout << "Enter username and password" << endl;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;


	bool login = false;
	//initial check if login credentials are correct
	if (username == "admin" && password == "password123") {
		login = true;
	}

	//if incorrect, checks each case for incorrect credentials
	while (login == false) {
		cout << "Login failed!" << endl;
		//if both are incorrect, re-enter both username and password
		if (username != "admin" && password != "password123") {
			cout << "Username and Password are incorrect! Re-enter." << endl;
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;
		}

		//if username is incorrect, re-enter username
		if (username != "admin" && password == "password123") {
			cout << "Username is incorrect! Re-enter username." << endl;
			cout << "Username: ";
			cin >> username;
		}

		//if password is incorrect, re-enter password
		if (username == "admin" && password != "password123") {
			cout << "Password is incorrect! Re-enter password." << endl;
			cout << "Password: ";
			cin >> password;
		}

		//if both are correct, exit while loop
		if (username == "admin" && password == "password123") {
			login = true;
		}
	}
	
	cout << "Login successful!" << endl;
}
