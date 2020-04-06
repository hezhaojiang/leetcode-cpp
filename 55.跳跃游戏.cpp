/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = 0;
        int maxPos = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            maxPos = max(i + nums[i], maxPos);
            if(i == end)
            {
                if(end == maxPos)
                {
                    return false;
                }
                end = maxPos;
            }
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution solve;
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(3);
    cout << solve.canJump(nums) << endl;
    return 0;
}