/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int N = nums.size();
        if (N < 3) return 0;
        sort(nums.begin(), nums.end());
        int res1 = nums[0] * nums[1] * nums[N - 1];
        int res2 = nums[N - 3] * nums[N - 2] * nums[N - 1];
        return max(res1, res2);
    }
};
// @lc code=end

