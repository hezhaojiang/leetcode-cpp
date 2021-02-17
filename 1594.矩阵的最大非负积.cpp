/*
 * @lc app=leetcode.cn id=1594 lang=cpp
 *
 * [1594] 矩阵的最大非负积
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
#define MOD 1000000007
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<long long>> mindp(M, vector<long long>(N, 0)); // 最小值
        vector<vector<long long>> maxdp(M, vector<long long>(N, 0)); // 最大值

        // 初始化左上角的值
        mindp[0][0] = maxdp[0][0] = grid[0][0];

        // 边界元素计算
        for (int i = 1; i < N; i++) {
            mindp[0][i] = maxdp[0][i] = maxdp[0][i - 1] * grid[0][i];
        }
        for (int i = 1; i < M; i++) {
            mindp[i][0] = maxdp[i][0] = maxdp[i - 1][0] * grid[i][0];
        }

        // 非边界元素计算
        for (int i = 1; i < M; i++) for (int j = 1; j < N; j++) {
            if (grid[i][j] >= 0) {
                maxdp[i][j] = max(maxdp[i - 1][j], maxdp[i][j - 1]) * grid[i][j];
                mindp[i][j] = min(mindp[i - 1][j], mindp[i][j - 1]) * grid[i][j];
            } else {
                mindp[i][j] = max(maxdp[i - 1][j], maxdp[i][j - 1]) * grid[i][j];
                maxdp[i][j] = min(mindp[i - 1][j], mindp[i][j - 1]) * grid[i][j];
            }
        }
        return maxdp[M - 1][N - 1] < 0 ? -1 : maxdp[M - 1][N - 1] % MOD;
    }
};
// @lc code=end
