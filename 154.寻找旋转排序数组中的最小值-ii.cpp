/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
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
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            /* 增加对相等值得比较 */
            if (nums[mid] == nums[end]) end--;
            else if (nums[mid] > nums[end])  start = mid;
            else end = mid;
        }
        return min(nums[start], nums[end]);
    }
};
// @lc code=end

