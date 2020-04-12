/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> money1;
    vector<int> money2;
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        for(int i = 0; i< nums.size() - 1; i++)
        {
            if(i == 0) money1.push_back(nums[i]);
            else if(i == 1) money1.push_back(max(nums[i],nums[i-1]));
            else money1.push_back(max(money1[i-2]+nums[i], money1[i-1]));
        }
        for(int i = 1; i< nums.size(); i++)
        {
            if(i == 1) money2.push_back(nums[i]);
            else if(i == 2) money2.push_back(max(nums[i],nums[i-1]));
            else money2.push_back(max(money2[i-3]+nums[i], money2[i-2]));
        }
        return max(money1.back(), money2.back());
    }
};
// @lc code=end

