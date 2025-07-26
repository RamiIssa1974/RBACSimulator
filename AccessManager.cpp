#include "AccessManager.h"

void AccessManager::addUser(const User& user) {
    users[user.getId()] = user;
}

void AccessManager::addRole(const Role& role) {
    roles[role.getId()] = role;
}

void AccessManager::addPermission(const Permission& permission) {
    permissions[permission.getId()] = permission;
}

bool AccessManager::userHasPermission(const std::string& userId, const std::string& permissionId) const {
    auto userIt = users.find(userId);
    if (userIt == users.end()) return false;

    const User& user = userIt->second;
    for (const std::string& roleId : user.getRoles()) {
        auto roleIt = roles.find(roleId);
        if (roleIt != roles.end()) {
            const Role& role = roleIt->second;
            for (const std::string& pId : role.getPermissions()) {
                if (pId == permissionId) return true;
            }
        }
    }

    return false;
}

User* AccessManager::getUser(const std::string& userId) {
    auto it = users.find(userId);
    return (it != users.end()) ? &(it->second) : nullptr;
}

Role* AccessManager::getRole(const std::string& roleId) {
    auto it = roles.find(roleId);
    return (it != roles.end()) ? &(it->second) : nullptr;
}

Permission* AccessManager::getPermission(const std::string& permissionId) {
    auto it = permissions.find(permissionId);
    return (it != permissions.end()) ? &(it->second) : nullptr;
}
