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
        if (nums.empty()) return result;
        int N = nums.size();

        /* 第一个位置 */
        int l = 0, r = N - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        if (l == N || nums[l] != target) return result;
        else result[0] = l;

        l = 0, r = N - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        result[1] = r;
        return result;
    }
};
// @lc code=end
