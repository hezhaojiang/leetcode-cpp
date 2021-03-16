/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int value = matrix[i][j];
                matrix[i][j] = matrix[i - 1][j] + value;
                if (j > 0) matrix[i][j] = min(matrix[i][j], matrix[i - 1][j - 1] + value);
                if (j != n - 1) matrix[i][j] = min(matrix[i][j], matrix[i - 1][j + 1] + value);
            }
        }
        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};
// @lc code=end
