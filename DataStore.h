#pragma once

#include "AccessManager.h"
#include "nlohmann/json.hpp"
#include <string>

class DataStore {
public:
    static void saveToFile(const std::string& filename, const AccessManager& manager);
    static void loadFromFile(const std::string& filename, AccessManager& manager);
};
