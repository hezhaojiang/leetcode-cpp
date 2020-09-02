/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int check = 0;
        int length = nums.size();
        for (int i = 0; i <= length; i++) check ^= i;
        for (int i = 0; i < length; i++) check ^= nums[i];
        return check;
    }
};
// @lc code=end

