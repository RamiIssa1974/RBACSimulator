#include "Role.h"
#include <algorithm>

Role::Role(const string& id, const string& name) : id(id), name(name) {}

string Role::getId() const {
    return id;
}

string Role::getName() const {
    return name;
}

void Role::setName(const string& newName) {
    name = newName;
}

const set<string>& Role::getPermissions() const {
    return permissions.getAll();

}

void Role::addPermission(const string& permissionId) {
    permissions.add(permissionId);

}

void Role::removePermission(const string& permissionId) {
    permissions.remove(permissionId);
}

void Role::addInheritedRole(const string& roleId) {
    if (find(inheritedRoleIds.begin(), inheritedRoleIds.end(), roleId) == inheritedRoleIds.end()) {
        inheritedRoleIds.push_back(roleId);
    }
}

const vector<string>& Role::getInheritedRoles() const {
    return inheritedRoleIds;
}

