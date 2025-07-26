#include "DataStore.h"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

void DataStore::saveToFile(const std::string& filename, const AccessManager& manager) {
    json j;

    // Save users
    for (const auto& pair : manager.getAllUsers()) {
        const User& user = pair.second;
        j["users"].push_back({
            {"id", user.getId()},
            {"name", user.getName()},
            {"roles", user.getRoles()}
            });
    }

    // Save roles
    for (const auto& pair : manager.getAllRoles()) {
        const Role& role = pair.second;
        j["roles"].push_back({
            {"id", role.getId()},
            {"name", role.getName()},
            {"permissions", role.getPermissions()}
            });
    }

    // Save permissions
    for (const auto& pair : manager.getAllPermissions()) {
        const Permission& p = pair.second;
        j["permissions"].push_back({
            {"id", p.getId()},
            {"description", p.getDescription()}
            });
    }

    std::ofstream file(filename);
    file << j.dump(4);
}

void DataStore::loadFromFile(const std::string& filename, AccessManager& manager) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "? Failed to open file: " << filename << std::endl;
        return;
    }
    json j;
    file >> j;

    for (const auto& ju : j["users"]) {
        User user(ju["id"], ju["name"]);
        for (const auto& rid : ju["roles"]) {
            user.addRole(rid);
        }
        manager.addUser(user);
    }

    for (const auto& jr : j["roles"]) {
        Role role(jr["id"], jr["name"]);
        for (const auto& pid : jr["permissions"]) {
            role.addPermission(pid);
        }
        manager.addRole(role);
    }

    for (const auto& jp : j["permissions"]) {
        Permission p(jp["id"], jp["description"]);
        manager.addPermission(p);
    }
}
