/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
#if 0
        vector<int> res;
        unordered_map<int, int> mp;
        for (auto & n : nums) mp[n]++;
        for (auto & m : mp) if (m.second == 1) res.push_back(m.first);
#endif
        int res = 0;
        int bitmask = 0;
        for (auto & n : nums) bitmask ^= n;
        int differ = 0;
        if (bitmask == INT_MIN) differ = INT_MIN;
        else differ = bitmask & (~bitmask + 1);
        for (auto & n : nums) if (n & differ) res ^= n;
        return {res, res ^ bitmask};
    }
};
// @lc code=end

