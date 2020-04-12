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
private:
    vector<int> money;
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        for(int i = 0; i< nums.size(); i++)
        {
            if(i == 0) money.push_back(nums[i]);
            else if(i == 1) money.push_back(max(nums[i],nums[i-1]));
            else money.push_back(max(money[i-2]+nums[i], money[i-1]));
        }
        return money.back();
    }
};
// @lc code=end

