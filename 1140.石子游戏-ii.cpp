/*
 * @lc app=leetcode.cn id=1140 lang=cpp
 *
 * [1140] 石子游戏 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    int n;
    vector<vector<int>> memo;  // 石子堆剩余 [i:] 且 M = j 时 先手玩家可以获得的最大石子数
    vector<int> sum;           // 后缀和 [i:]
    int dfs(vector<int>& piles, int start, int M) {
        if (start == n) return 0;
        if (start + 2 * M >= n) return sum[start];
        if (memo[start][M] != INT_MAX) return memo[start][M];
        int res = 0;
        for (int X = 1; X <= 2 * M; X++) {
            res = max(res, sum[start] - dfs(piles, start + X, max(X, M)));
        }
        return memo[start][M] = res;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memo.resize(n, vector<int>(n, INT_MAX));
        sum.resize(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) sum[i] = sum[i + 1] + piles[i];
        return dfs(piles, 0, 1);
    }
};
// @lc code=end
