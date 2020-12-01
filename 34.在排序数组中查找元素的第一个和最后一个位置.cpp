/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> result{-1, -1};
        if(nums.size() == 0) return result;
        int start = 0, mid, end = nums.size() - 1;
        while (start < end - 1) {
            mid = start + (end - start) / 2;
            if (nums[mid] >= target) end = mid;
            if (nums[mid] < target) start = mid + 1;
        }

        if (nums[start] != target && nums[end] != target) return result;
        else if (nums[start] == target) result[0] = start;
        else result[0] = end;

        start = 0, mid, end = nums.size() - 1;
        while (start < end - 1) {
            mid = start + (end - start) / 2;
            if (nums[mid] > target) end = mid - 1;
            if (nums[mid] <= target) start = mid;
        }
        if (nums[end] == target) result[1] = end;
        else result[1] = start;
        return result;
    }
};
// @lc code=end
