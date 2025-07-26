#include "Role.h"
#include <algorithm>

Role::Role(const std::string& id, const std::string& name) : id(id), name(name) {}

std::string Role::getId() const {
    return id;
}

std::string Role::getName() const {
    return name;
}

void Role::setName(const std::string& newName) {
    name = newName;
}

const std::vector<std::string>& Role::getPermissions() const {
    return permissionIds;
}

void Role::addPermission(const std::string& permissionId) {
    if (std::find(permissionIds.begin(), permissionIds.end(), permissionId) == permissionIds.end())
        permissionIds.push_back(permissionId);
}

void Role::removePermission(const std::string& permissionId) {
    permissionIds.erase(
        std::remove(permissionIds.begin(), permissionIds.end(), permissionId),
        permissionIds.end()
    );
}
