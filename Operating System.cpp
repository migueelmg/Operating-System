#include <iostream>
#include <string>

void bootingSystem(std::string username) {
    std::cout << "Hello " << username << "!\n";
    std::cout << "Updating and verifying services...\n";
    std::cout << "10\n";
    std::cout << "9\n";
    std::cout << "8\n";
    std::cout << "7\n";
    std::cout << "6\n";
    std::cout << "5\n";
    std::cout << "4\n";
    std::cout << "3\n";
    std::cout << "2\n";
    std::cout << "1\n";

}


int main()
{
    std::string username;
    std::cout << "Username: ";
    std::cin >> username;
    bootingSystem(username);
    return 0;
}

