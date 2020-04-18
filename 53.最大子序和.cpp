/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxSubSum = nums[0];
        int maxSubCur = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            maxSubCur = maxSubCur > 0 ? maxSubCur + nums[i] : nums[i];
            if(maxSubCur > maxSubSum) maxSubSum = maxSubCur;
        }
        return maxSubSum;
    }
};
// @lc code=end

