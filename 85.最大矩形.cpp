/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') left[i][j] = (j == 0 ? 0: left[i][j - 1]) + 1;
        }

        int ret = 0;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '0') continue;
            int width = left[i][j], area = width;
            for (int k = i - 1; k >= 0; k--) {
                width = min(width, left[k][j]);
                area = max(area, (i - k + 1) * width);
            }
            ret = max(ret, area);
        }
        return ret;
    }
};
// @lc code=end

/* Test Main */
int main(void)
{
    Solution solve;
    vector<vector<char>> matrix{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    solve.maximalRectangle(matrix);
    return 0;
}
