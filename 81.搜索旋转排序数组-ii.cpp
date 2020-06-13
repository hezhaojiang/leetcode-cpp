/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(!nums.size()) return false;
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;
        while(start + 1 < end)
        {
            if(nums[mid] == target) return true;
            else if (nums[mid] == nums[start]) start++;
            else if (nums[mid] == nums[end]) end--;
            else if (nums[mid] > nums[start]) {
                if(target >= nums[start] && target < nums[mid])
                    end = mid;
                else
                    start = mid;
            }
            else {
                if(target <= nums[end] && target > nums[mid])
                    start = mid;
                else
                    end = mid;
            }
            mid = start + (end - start) / 2;
        }
        if (nums[start] == target) return true;
        else if (nums[end] == target) return true;
        return false;
    }
};
// @lc code=end

