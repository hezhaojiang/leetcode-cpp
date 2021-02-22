/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 */
#include<vector>
#include<set>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int N = nums.size();
        int l = 0, r = 0, res = 0;
        multiset<int> bst;
        while (r < N) {
            bst.insert(nums[r++]);
            if (*bst.rbegin() - *bst.begin() > limit) {
                bst.erase(bst.find(nums[l++]));
            }
            res = max(res, r - l);
        }
        return res;
    }
};
// @lc code=end

