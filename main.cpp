// RBACSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Role.h"
#include "User.h"
#include "AccessManager.h"
#include "nlohmann/json.hpp"
#include "DataStore.h"
#include "SimplePermissionEvaluator.h"
#include "PermissionSet.h"
#include "RoleCycleDetector.h"
using json = nlohmann::json;

using namespace std;
mutex coutMutex;
 
 

void checkPermission(AccessManager& manager,
	const string& userId,
	const string& permissionId) {
	
	lock_guard<mutex> lock(coutMutex);
	SimplePermissionEvaluator evaluator;

	bool has = manager.userHasPermission(userId, permissionId, evaluator);
	cout << "Thread: User " << userId
		<< (has ? " HAS " : " DOES NOT HAVE ")
		<< "permission " << permissionId << endl;
}

int main()
{ 
	AccessManager manager;

	Role admin("admin", "Administrator");
	admin.addPermission("manage");
	admin.addInheritedRole("writer");

	Role writer("writer", "Writer");
	writer.addPermission("write");
	// writer.addInheritedRole("admin");  // נסה להפעיל את זה כדי ליצור מעגל

	manager.addRole(admin);
	manager.addRole(writer);

	if (RoleCycleDetector::hasCycle(manager)) {
		cout << "Cycle detected in role inheritance!" << endl;
	}
	else {
		cout << "No cycles in role inheritance." << endl;
	}

	cin.get();
	return 0;

	SimplePermissionEvaluator evaluator;
	
	const string dsfilename = "c:\\Temp\\RBACSimulator\\data.json";
	DataStore::loadFromFile(dsfilename, manager);

	thread t1(checkPermission, ref(manager), "0263", "read");
	thread t2(checkPermission, ref(manager), "0263", "write");
	thread t3(checkPermission, ref(manager), "0263", "admin");

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
	else if (!manager.userHasPermission("0263", "write", evaluator)) {
		Permission per("write", "can write");
		manager.addPermission(per);

		Role role("100", "Writer");
		role.addPermission("write");
		manager.addRole(role);
		dsUser->addRole("100");
		DataStore::saveToFile(dsfilename, manager);
	}




	if (manager.userHasPermission("0263", "write", evaluator)) {
		cout << "User " << manager.getUser("0263")->getName() << " has WRITE permission\n";
	}
	else {
		cout << "User does NOT have WRITE permission\n";
	}


	cin.get();
}

