/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
//#define REVERSE
#define DYNAMIC_PROGRAMMING
#ifdef REVERSE
private:
    int dfs(vector<int>&nums, int start, int end, int turn) {
        if (end == start) return nums[start] * turn;
        int scoreStart = nums[start] * turn + dfs(nums, start + 1, end, -turn);
        int scoreEnd = nums[end] * turn + dfs(nums, start, end - 1, -turn);
        return max(scoreStart * turn, scoreEnd * turn) * turn;
    }
#endif
public:
    bool PredictTheWinner(vector<int>& nums) {
#ifdef REVERSE
        int score = dfs(nums, 0, nums.size() - 1, 1);
        return score >= 0;
#endif
#ifdef DYNAMIC_PROGRAMMING
        int length = nums.size();
        auto dp = vector<vector<int>> (length, vector<int>(length));
        for (int i = 0; i < length; i++) dp[i][i] = nums[i];
        /* dp[i][j]=max(nums[i]−dp[i+1][j],nums[j]−dp[i][j−1]) */
        for (int i = length - 2; i >= 0; i--)
            for (int j = i + 1; j < length; j++)
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        return dp[0][length - 1] >= 0;
#endif
    }
};
// @lc code=end

