#pragma once
#include <set>
using namespace std;
template<typename T>
class PermissionSet {
private:
    set<T> items;

public:
    void add(const T& item) {
        items.insert(item);
    }

    void remove(const T& item) {
        items.erase(item);
    }

    bool contains(const T& item) const {
        return items.find(item) != items.end();
    }

    size_t size() const {
        return items.size();
    }

    void clear() {
        items.clear();
    }

    const set<T>& getAll() const {
        return items;
    }
};
