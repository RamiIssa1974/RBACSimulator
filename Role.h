#pragma once
#include <string>
#include <set>
#include "PermissionSet.h"
 
using namespace std;
class Role {
private:
    string id;
    string name;
    PermissionSet<string> permissions;

public:
    Role() = default;
    Role(const string& id, const string& name);

    string getId() const;
    string getName() const;
    void setName(const string& newName);

    const set<string>& getPermissions() const;
    void addPermission(const string& permissionId);
    void removePermission(const string& permissionId);
};
