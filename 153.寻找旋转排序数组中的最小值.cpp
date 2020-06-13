/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (!nums.size()) return INT_MIN;
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;
        while (start + 1 < end)
        {
            /* 最小值 */
            if (nums[mid] < nums[mid-1]) 
                return nums[mid];
            /* 最大值 */  
            else if (nums[mid] > nums[mid+1])
                return nums[mid+1];
            /* 上升中 */  
            else if (nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]) {
                /* 第一个上升阶段 且 存在第二个上升阶段 */
                if (nums[mid] > nums[start] && nums[start] > nums[end]) 
                    start = mid;
                else /* 不存在第二个上升阶段 or 处于第二个上升阶段 */
                    end = mid;
            }
            else return INT_MIN; /* 下降 不应该出现 */
            mid = start + (end - start) / 2;
        }
        return min(nums[start], nums[end]);
    }
};
// @lc code=end

