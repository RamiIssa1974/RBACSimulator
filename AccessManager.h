#pragma once

#include <map>
#include <string>
#include "User.h"
#include "Role.h"
#include "Permission.h"

class AccessManager {
private:
    std::map<std::string, User> users;
    std::map<std::string, Role> roles;
    std::map<std::string, Permission> permissions;

public:
    void addUser(const User& user);
    void addRole(const Role& role);
    void addPermission(const Permission& permission);

    bool userHasPermission(const std::string& userId, const std::string& permissionId) const;

    User* getUser(const std::string& userId);
    Role* getRole(const std::string& roleId);
    Permission* getPermission(const std::string& permissionId);
};
