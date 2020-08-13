/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */
#include<unordered_map>
#include<vector>
using namespace std;
// @lc code=start
class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>::iterator> _table;
    list<pair<int, int>> _lru;
    int _capacity;
public:
    LRUCache(int capacity) : _capacity(capacity) {

    }
    
    int get(int key) {
        auto it = _table.find(key);
        if (it != _table.end()) {
            _lru.splice(_lru.begin(), _lru, it->second);
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = _table.find(key);
        if (it != _table.end()) {
            _lru.splice(_lru.begin(), _lru, it->second);
            it->second->second = value;
            return;
        }
        
        _lru.emplace_front(key, value);
        _table[key] = _lru.begin();
        
        if (_table.size() > _capacity) {
            _table.erase(_lru.back().first);
            _lru.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

