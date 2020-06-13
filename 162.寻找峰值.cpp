/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (!nums.size()) return INT_MIN;
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;
        while (start + 1 < end)
        {
            if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return mid;
            else if (nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1]) start = mid;
            else if (nums[mid-1] > nums[mid] && nums[mid] > nums[mid+1]) end = mid;
            else start = mid;
            mid = start + (end - start) / 2;
        }
        return (nums[start] > nums[end])?start:end;
    }
};
// @lc code=end

