/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (!nums.size()) return false;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[r]) r--;
            else if (target > nums[r]) {
                if (nums[l] <= nums[mid] && nums[mid] < target) l = mid + 1;
                else r = mid - 1;
            } else {
                if (target < nums[mid] && nums[mid] <= nums[r]) r = mid - 1;
                else l = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end
