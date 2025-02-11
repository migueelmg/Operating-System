#pragma once
#include <iostream>
#include <string>
using namespace std;

void authenticateUser() {
	string username;
	string password;
	cout << "Enter username and password" << endl;
	cout << "Username:" << endl;
	cin >> username;
	cout << "Password: " << endl;
	cin >> password;

	if (username == "admin" and password == "password123") {
		cout << "Login successful!" << endl;
	}
	else {
		cout << "Login failed!" << endl;
	}
}
