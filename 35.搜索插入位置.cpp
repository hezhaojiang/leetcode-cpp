/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        while(left + 1 < right)
        {
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) 
                left = mid;
            if(nums[mid] > target) 
                right = mid;
            mid = left + (right - left) / 2;
        }
        if(target > nums[right]) return right + 1;
        else if(target <= nums[left]) return left;
        else return right;
    }
};
// @lc code=end

