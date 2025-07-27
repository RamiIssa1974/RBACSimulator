#pragma once
#include "AccessManager.h"
#include <unordered_set>
#include <string>
using namespace std;
/// <summary>
/// למנוע מבנה מעגלי (Cycle) בין תפקידים שמורשים אחד מהשני, כדי לא לגרום ל:
/// לולאות אינסופיות
/// קריסות בתהליכי בדיקה רקורסיביים
/// הרשאות בלתי צפויות
/// </summary>
class RoleCycleDetector {
public:
    static bool hasCycle(const AccessManager& manager);
private:
    static bool dfs(const string& roleId,
        const AccessManager& manager,
        unordered_set<string>& visited,
        unordered_set<string>& recursionStack);
};
