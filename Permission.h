#pragma once
#include <string>

class Permission {
private:
    std::string id;
    std::string description;

public:
    Permission() = default;
    Permission(const std::string& id, const std::string& description);

    std::string getId() const;
    std::string getDescription() const;
    void setDescription(const std::string& newDescription);
};
