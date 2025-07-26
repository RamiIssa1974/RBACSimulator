#pragma once
#include <string>
#include <vector>

class User {
private:
    std::string id;
    std::string name;
    std::vector<std::string> roleIds;

public:
    User() = default;
    User(const std::string& id, const std::string& name);

    std::string getId() const;
    std::string getName() const;
    void setName(const std::string& newName);

    const std::vector<std::string>& getRoles() const;
    void addRole(const std::string& roleId);
    void removeRole(const std::string& roleId);
};
