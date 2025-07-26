// RBACSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Role.h"
#include "User.h"
#include "AccessManager.h"
#include "nlohmann/json.hpp"
#include "DataStore.h"
using json = nlohmann::json;

using namespace std;
std::mutex coutMutex;

void checkPermission(AccessManager& manager,
	const std::string& userId,
	const std::string& permissionId) {
	
	std::lock_guard<std::mutex> lock(coutMutex);
	bool has = manager.userHasPermission(userId, permissionId);
	std::cout << "Thread: User " << userId
		<< (has ? " HAS " : " DOES NOT HAVE ")
		<< "permission " << permissionId << endl;
}

int main()
{
	AccessManager manager;
	const string dsfilename = "c:\\Temp\\RBACSimulator\\data.json";
	DataStore::loadFromFile(dsfilename, manager);

	std::thread t1(checkPermission, std::ref(manager), "0263", "read");
	std::thread t2(checkPermission, std::ref(manager), "0263", "write");
	std::thread t3(checkPermission, std::ref(manager), "0263", "admin");

	t1.join();
	t2.join();
	t3.join();
	
	auto dsUser = manager.getUser("0263");
	if (dsUser == nullptr) {
		Permission p("read", "Can read");
		manager.addPermission(p);
		Role r("101", "Reader");
		r.addPermission("read");
		manager.addRole(r);
		User u("0263", "Rami");
		u.addRole("101");
		manager.addUser(u);

		DataStore::saveToFile(dsfilename, manager);
	}
	else if (!manager.userHasPermission("0263", "write")) {
		Permission per("write", "can write");
		manager.addPermission(per);

		Role role("100", "Writer");
		role.addPermission("write");
		manager.addRole(role);
		dsUser->addRole("100");
		DataStore::saveToFile(dsfilename, manager);
	}




	if (manager.userHasPermission("0263", "write")) {
		std::cout << "User " << manager.getUser("0263")->getName() << " has WRITE permission\n";
	}
	else {
		std::cout << "User does NOT have WRITE permission\n";
	}


	cin.get();
}

