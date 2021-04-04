/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] 常数时间插入、删除和获取随机元素
 */
#include <unordered_map>
using namespace std;
// @lc code=start
class RandomizedSet {
private:
    unordered_map<int, int> val_pos;
    vector<int> nums;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified
     * element. */
    bool insert(int val) {
        if (val_pos.count(val)) return false;
        val_pos[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!val_pos.count(val)) return false;
        int pos = val_pos[val];
        val_pos[nums.back()] = pos;  // 将 nums 最后一位替换到删除元素的位置
        nums[pos] = nums.back();
        val_pos.erase(val);  // 删除操作
        nums.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int pos = rand() % nums.size();
        return nums[pos];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
