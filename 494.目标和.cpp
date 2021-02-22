/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    int dfs(vector<int>& nums, int pos, int R, int S) {
        if (pos == nums.size()) return R == S;
        return dfs(nums, pos + 1, R + nums[pos], S) + dfs(nums, pos + 1, R - nums[pos], S);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) { return dfs(nums, 0, 0, S); }
};
// @lc code=end
