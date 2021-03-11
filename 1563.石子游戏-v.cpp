/*
 * @lc app=leetcode.cn id=1563 lang=cpp
 *
 * [1563] 石子游戏 V
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    int n;
    vector<vector<int>> memo;
    vector<int> sum;
    int dfs(vector<int>& stoneValue, int start, int end) {
        if (start == end) return 0;
        if (memo[start][end] != INT_MAX) return memo[start][end];
        int score = 0;
        for (int i = start + 1; i <= end; i++) {
            int l = sum[i] - sum[start];
            int r = sum[end + 1] - sum[i];
            if (l < r) score = max(score, l + dfs(stoneValue, start, i - 1));
            else if (l > r) score = max(score, r + dfs(stoneValue, i, end));
            else score = max(score, max(l + dfs(stoneValue, start, i - 1), r + dfs(stoneValue, i, end)));
        }
        return memo[start][end] = score;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        memo.resize(n, vector<int>(n, INT_MAX));
        sum.resize(n + 1, 0);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + stoneValue[i];
        return dfs(stoneValue, 0, n - 1);
    }
};
// @lc code=end
