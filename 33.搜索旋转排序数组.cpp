/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] == target) return mid;
            if (target > nums[r]) {
                if (nums[l] <= nums[mid] && nums[mid] < target) l = mid + 1;
                else r = mid - 1;
            } else {
                if (target < nums[mid] && nums[mid] <= nums[r]) r = mid - 1;
                else l = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

