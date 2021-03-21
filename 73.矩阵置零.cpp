/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool rowline = false, colline = false;
        for (int i = 0; i < m; i++) if (!matrix[i][0]) rowline = true;
        for (int j = 0; j < n; j++) if (!matrix[0][j]) colline = true;
        for (int i = 1; i < m; i++) for (int j = 1; j < n; j++) {
            if (!matrix[i][j]) matrix[i][0] = matrix[0][j] = 0;
        }
        for (int i = m - 1; i > 0; i--) for (int j = n - 1; j > 0; j--) {
            if (!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
        }
        if (rowline) for (int i = 0; i < m; i++) matrix[i][0] = 0;
        if (colline) for (int j = 0; j < n; j++) matrix[0][j] = 0;
    }
};
// @lc code=end
