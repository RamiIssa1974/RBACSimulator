#include "AccessManager.h"

void AccessManager::addUser(const User& user) {    
    users[user.getId()] = make_shared<User>(user);
}

void AccessManager::addRole(const Role& role) {
    roles[role.getId()] = make_shared<Role>(role);
}

void AccessManager::addPermission(const Permission& permission) {
    permissions[permission.getId()] = make_shared<Permission>(permission);
}

bool AccessManager::userHasPermission(
    const std::string& userId,
    const std::string& permissionId,
    const IPermissionEvaluator& evaluator) const {

    std::lock_guard<std::mutex> lock(accessMutex);

    auto userIt = users.find(userId);
    if (userIt == users.end()) return false;
    auto user = userIt->second;

    auto permIt = permissions.find(permissionId);
    if (permIt == permissions.end()) return false;
    auto permission = permIt->second;

    for (const std::string& roleId : user->getRoles()) {
        auto roleIt = roles.find(roleId);
        if (roleIt != roles.end()) {
            auto role = roleIt->second;
            if (evaluator.evaluate(*user, *role, *permission)) {
                return true;
            }
        }
    }

    return false;
}

shared_ptr<User> AccessManager::getUser(const std::string& userId) {
    auto it = users.find(userId);
    return (it != users.end()) ? it->second : nullptr;
}

shared_ptr<Role> AccessManager::getRole(const std::string& roleId) const {
    auto it = roles.find(roleId);
    return (it != roles.end()) ? it->second : nullptr;
}

shared_ptr<Permission> AccessManager::getPermission(const std::string& permissionId) {
    auto it = permissions.find(permissionId);
    return (it != permissions.end()) ? it->second : nullptr;
}

const map<string, shared_ptr<User>>& AccessManager::getAllUsers() const {
    return users;
}

const std::map<string, shared_ptr<Role>>& AccessManager::getAllRoles() const {
    return roles;
}

const std::map<string, shared_ptr<Permission>>& AccessManager::getAllPermissions() const {
    return permissions;
}

