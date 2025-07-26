#include "SimplePermissionEvaluator.h"
bool SimplePermissionEvaluator::evaluate(const User& user,
                                         const Role& role,
                                         const Permission& permission) const {
    for (const std::string& permId : role.getPermissions()) {
        if (permId == permission.getId()) {
            return true;
        }
    }
    return false;
}
