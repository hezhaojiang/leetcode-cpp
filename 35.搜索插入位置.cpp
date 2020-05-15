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
        int mid = (left + right) / 2;
        while(mid != right)
        {
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) 
            {
                left = mid + 1;
                mid = (left + right) / 2;
            }
            else
            {
                right = mid;
                mid = (left + right) / 2;
            }
        }
        return nums[mid]<target?mid+1:mid;
    }
};
// @lc code=end

