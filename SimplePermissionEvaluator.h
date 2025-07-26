#pragma once
#include "IPermissionEvaluator.h"
class SimplePermissionEvaluator : public IPermissionEvaluator
{
public:
    bool evaluate(const User& user,
                  const Role& role,
                  const Permission& permission) const override;

};

