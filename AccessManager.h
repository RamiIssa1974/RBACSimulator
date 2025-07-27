#pragma once

#include <map>
#include <string>
#include "User.h"
#include "Role.h"
#include "Permission.h"
#include <mutex>
#include "IPermissionEvaluator.h"
using namespace std;
class AccessManager {
private:
    map<string, shared_ptr<User>> users;
    map<string, shared_ptr<Role>> roles;
    map<string, shared_ptr<Permission>> permissions;

    mutable mutex accessMutex;

public:
    void addUser(const User& user);
    void addRole(const Role& role);
    void addPermission(const Permission& permission);

    bool userHasPermission(const std::string& userId,
        const std::string& permissionId,
        const IPermissionEvaluator& evaluator) const;

    shared_ptr<User> getUser(const string& userId);
    shared_ptr<Role> getRole(const string& roleId) const;
    shared_ptr<Permission> getPermission(const std::string& permissionId);

    const map<string, shared_ptr<User>>& getAllUsers() const;
    const map<string, shared_ptr<Role>>& getAllRoles() const;
    const map<string, shared_ptr<Permission>>& getAllPermissions() const;
     

};
