/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty()) return false;
        sort(nums.begin(), nums.end());
        int first = nums[0];
        for(int i = 1; i < nums.size(); i++)
            if(first == nums[i]) return true;
            else first = nums[i];
        return false;
    }
};
// @lc code=end

