/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
#define REVERSE
#ifdef REVERSE
private:
    int n;
    vector<vector<int>> memo; // 在 i ~ j 之间 先手比后手多拿到的分数
    int dfs(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        if (memo[start][end] != INT_MAX) return memo[start][end];
        memo[start][end] = max(nums[start] - dfs(nums, start + 1, end), nums[end] - dfs(nums, start, end - 1));
        return memo[start][end];
    }
#endif
public:
    bool PredictTheWinner(vector<int>& nums) {
#ifdef REVERSE
        n = nums.size();
        memo.resize(n, vector<int>(n, INT_MAX));
        int score = dfs(nums, 0, n - 1);
        return score >= 0;
#endif
#ifdef DYNAMIC_PROGRAMMING
        int length = nums.size();
        auto dp = vector<vector<int>>(length, vector<int>(length));
        for (int i = 0; i < length; i++) dp[i][i] = nums[i];
        /* dp[i][j] = max(nums[i] − dp[i+1][j], nums[j] − dp[i][j−1]) */
        for (int i = length - 2; i >= 0; i--)
            for (int j = i + 1; j < length; j++) dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        return dp[0][length - 1] >= 0;
#endif
    }
};
// @lc code=end
