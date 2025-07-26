#pragma once

#include "User.h"
#include "Role.h"
#include "Permission.h"

class IPermissionEvaluator {
public:
    virtual bool evaluate(const User& user,
        const Role& role,
        const Permission& permission) const = 0;

    virtual ~IPermissionEvaluator() = default;
};
