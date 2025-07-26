#pragma once
#include <string>
#include <vector>

class Role {
private:
    std::string id;
    std::string name;
    std::vector<std::string> permissionIds;

public:
    Role() = default;
    Role(const std::string& id, const std::string& name);

    std::string getId() const;
    std::string getName() const;
    void setName(const std::string& newName);

    const std::vector<std::string>& getPermissions() const;
    void addPermission(const std::string& permissionId);
    void removePermission(const std::string& permissionId);
};
