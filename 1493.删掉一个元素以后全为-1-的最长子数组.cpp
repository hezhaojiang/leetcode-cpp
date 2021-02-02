/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int N = nums.size();
        int onecount = 0;
        int left = 0, right = 0;
        while (right < N) {
            onecount += nums[right++] == 1;
            if (right - left - onecount > 1) onecount -= nums[left++] == 1;
        }
        return right - left - 1;
    }
};
// @lc code=end

