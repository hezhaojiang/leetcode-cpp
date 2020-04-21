/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> length;
        length.resize(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            int maxlength = 0;
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i] && maxlength < length[j])
                    maxlength = length[j];
            }
            length[i] = maxlength + 1;
        }
        int maxlength = 0;
        for(auto a : length)
            if(a > maxlength) maxlength = a;
        return maxlength;
    }
};
// @lc code=end

