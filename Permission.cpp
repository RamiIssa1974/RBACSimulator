#include "Permission.h"

Permission::Permission(const std::string& id, const std::string& description)
    : id(id), description(description) {
}

std::string Permission::getId() const {
    return id;
}

std::string Permission::getDescription() const {
    return description;
}

void Permission::setDescription(const std::string& newDescription) {
    description = newDescription;
}
