/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */
#include <vector>
using namespace std;
// @lc code=start
class NumMatrix {
private:
    vector<vector<int>> sum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int M = matrix.size();
        int N = matrix[0].size();
        sum.resize(M + 1, vector<int>(N + 1, 0));
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++)
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + matrix[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
