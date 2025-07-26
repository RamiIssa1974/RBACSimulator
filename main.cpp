// RBACSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Role.h"
#include "User.h"
#include "AccessManager.h"
using namespace std;

int main()
{
    AccessManager manager;

    manager.addPermission(Permission("read", "Read data"));
    manager.addPermission(Permission("write", "Write data"));

    Role writer("100", "Writer");
    writer.addPermission("read");
    writer.addPermission("write");

    manager.addRole(writer);

    User rami("0263", "Rami Issa");
    rami.addRole("100");

    manager.addUser(rami);

    if (manager.userHasPermission("0263", "write")) {
        std::cout << "User " << manager.getUser("0263")->getName() << " has WRITE permission\n";
    }
    else {
        std::cout << "User does NOT have WRITE permission\n";
    }

    
    cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
