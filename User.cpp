#include "User.h"
#include <algorithm>

User::User(const std::string& id, const std::string& name) : id(id), name(name) {}

std::string User::getId() const {
    return id;
}

std::string User::getName() const {
    return name;
}

void User::setName(const std::string& newName) {
    name = newName;
}

const std::vector<std::string>& User::getRoles() const {
    return roleIds;
}

void User::addRole(const std::string& roleId) {
    if (std::find(roleIds.begin(), roleIds.end(), roleId) == roleIds.end())
        roleIds.push_back(roleId);
}

void User::removeRole(const std::string& roleId) {
    roleIds.erase(
        std::remove(roleIds.begin(), roleIds.end(), roleId),
        roleIds.end()
    );
}
