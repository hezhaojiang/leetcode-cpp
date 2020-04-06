/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int end = 0;
        int jumpnum = 0;
        int maxPos = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            maxPos = max(i + nums[i], maxPos);
            if(i == end)
            {
                end = maxPos;
                jumpnum++;
            }
        }
        return jumpnum;
    }
};
// @lc code=end

