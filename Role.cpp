#include "Role.h"
#include <algorithm>

Role::Role(const std::string& id, const std::string& name) : id(id), name(name) {}

std::string Role::getId() const {
    return id;
}

std::string Role::getName() const {
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
