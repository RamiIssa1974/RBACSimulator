#include "RoleCycleDetector.h"

bool RoleCycleDetector::hasCycle(const AccessManager& manager) {
    unordered_set<string> visited;
    unordered_set<string> recursionStack;

    for (const auto& pair : manager.getAllRoles()) {
        const auto& role = pair.second;
        const string& roleId = role->getId();

        if (visited.find(roleId) == visited.end()) {
            if (dfs(roleId, manager, visited, recursionStack)) {
                return true;
            }
        }
    }
    return false;
}

bool RoleCycleDetector::dfs(const string& roleId,
    const AccessManager& manager,
    unordered_set<string>& visited,
    unordered_set<string>& recursionStack) {
    visited.insert(roleId);
    recursionStack.insert(roleId);

    auto role = manager.getRole(roleId);
    if (role) {
        for (const string& inheritedId : role->getInheritedRoles()) {
            if (recursionStack.find(inheritedId) != recursionStack.end()) {
                return true;  // Detected cycle
            }
            if (visited.find(inheritedId) == visited.end()) {
                if (dfs(inheritedId, manager, visited, recursionStack)) {
                    return true;
                }
            }
        }
    }

    recursionStack.erase(roleId);
    return false;
}
