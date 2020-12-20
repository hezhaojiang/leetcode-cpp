/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> money(1, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) money.push_back(nums[i]);
            else money.push_back(max(money[i - 1] + nums[i], money[i]));
        }
        return money.back();
    }
};
// @lc code=end

