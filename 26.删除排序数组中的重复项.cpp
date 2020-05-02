/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
#include<vector> 
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int lastNumber = nums[0];
        int index = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != lastNumber) nums[index++] = nums[i];
            lastNumber = nums[i];
        }
        return index;
    }
};
// @lc code=end

