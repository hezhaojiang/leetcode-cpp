/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size()) return -1;
        int start = 0;
        int end = nums.size() - 1;
        int mid = (start + end) / 2;
        while(nums[mid] != target && mid != end)
        {
            if(nums[start] <= nums[mid]) //左侧正常
            {
                if(nums[start] <= target && target <= nums[mid])
                {
                    end = mid;
                    mid = (start + end) / 2;
                }
                else
                {
                    start = mid + 1;
                    mid = (start + end) / 2;
                }
            }
            else if(nums[mid] < nums[end]) //右侧正常
            {
                if(nums[mid] <= target && target <= nums[end])
                {
                    start = mid + 1;
                    mid = (start + end) / 2;
                }
                else
                {
                    end = mid;
                    mid = (start + end) / 2;
                }
            }
        }
        if(nums[mid] == target) return mid;
        return -1;
    }
};
// @lc code=end

