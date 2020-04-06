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
        int i = 0;
        int end = nums.size() - 1;
        while(i < end)
        {
            if (i + nums[i] >= end)
            {
                end = i;
                i = 0;
            }
            else
            {
                i++;
            }
        }
        if(i == end && end != 0)
        {
            return false;
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