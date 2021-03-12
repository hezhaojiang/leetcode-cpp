/*
 * @lc app=leetcode.cn id=1690 lang=cpp
 *
 * [1690] 石子游戏 VII
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    int n;
    vector<vector<int>> memo;
    vector<int> sum;
    int dfs(int start, int end) {
        if (start == end) return 0;
        if (memo[start][end] != INT_MAX) return memo[start][end];
        int score =
            max(sum[end + 1] - sum[start + 1] - dfs(start + 1, end), sum[end] - sum[start] - dfs(start, end - 1));
        return memo[start][end] = score;
    }

public:
    int stoneGameVII(vector<int>& stones) {
        n = stones.size();
        memo.resize(n, vector<int>(n, INT_MAX));
        sum.resize(n + 1, 0);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + stones[i];
        return dfs(0, n - 1);
    }
};
// @lc code=end
