/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int l = -1, r = 0, N = nums.size();
        while (r < N) {
            if (nums[r] == 1) res = max(res, r++ - l);
            else l = r++;
        }
        return res;
    }
};
// @lc code=end
