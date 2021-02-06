/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int N = nums.size();
        int left = 0, right = 0;
        double average = INT_MIN, total = 0;
        while (right < N) {
            total += nums[right++];
            if (right > k) total -= nums[left++];
            if (right >= k) average = max(total / k, average);
        }
        return average;
    }
};
// @lc code=end

