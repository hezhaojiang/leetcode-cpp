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
        int N = nums.size();
        int res = N;
        for (int i = 0; i < N; i++) res ^= i ^ nums[i];
        return res;
    }
};
// @lc code=end

