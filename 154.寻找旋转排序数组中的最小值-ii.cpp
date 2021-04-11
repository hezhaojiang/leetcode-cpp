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
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] == nums[r]) r--;
            else if (nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};
// @lc code=end

