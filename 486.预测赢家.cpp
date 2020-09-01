/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    int dfs(vector<int>&nums, int start, int end, int turn) {
        if (end == start) return nums[start] * turn;
        int scoreStart = nums[start] * turn + dfs(nums, start + 1, end, -turn);
        int scoreEnd = nums[end] * turn + dfs(nums, start, end - 1, -turn);
        return max(scoreStart * turn, scoreEnd * turn) * turn;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int score = dfs(nums, 0, nums.size() - 1, 1);
        return score >= 0;
    }
};
// @lc code=end

