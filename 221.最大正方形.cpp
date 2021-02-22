/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    if (matrix[i][j] == '1') dp[i][j] = 1, res = max(res, 1);
                    continue;
                }
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        return res * res;
    }
};
// @lc code=end
