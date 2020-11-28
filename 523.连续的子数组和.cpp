/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<long long> preSum(1, 0);
        for (auto n : nums) preSum.push_back(preSum.back() + n);
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                long long dif = preSum[j + 1] - preSum[i];
                if ((k == 0 && dif == 0) || (k != 0 && dif % k == 0)) return true;
            }
        }
        return false;
    }
};
// @lc code=end

