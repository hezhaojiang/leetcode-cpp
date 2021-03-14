/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */
#include <list>
#include <vector>
using namespace std;

// @lc code=start
class MyHashMap {
    const int mod = 9973;
    vector<list<pair<int, int>>> stor;

public:
    /** Initialize your data structure here. */
    MyHashMap() { stor.resize(mod); }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int pos = key % mod;
        for (auto& l : stor[pos]) {
            if (l.first == key) {
                l.second = value;
                return;
            }
        }
        stor[pos].push_back(make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int pos = key % mod;
        for (auto& l : stor[pos]) {
            if (l.first == key) return l.second;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto& s = stor[key % mod];
        for (auto it = s.begin(); it != s.end(); it++) {
            if ((*it).first == key) {
                it = s.erase(it);
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
