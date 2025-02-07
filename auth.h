#pragma once
#include <iostream>
#include <string>
using namespace std;

string authenticateUser(string username, string password) {
	if (username == "admin" and password == "password123") {
		return "Login successful!";
	}
	else {
		return "Login failed!";
	}
}

