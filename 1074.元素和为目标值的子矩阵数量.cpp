/*
 * @lc app=leetcode.cn id=1074 lang=cpp
 *
 * [1074] 元素和为目标值的子矩阵数量
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ret = 0;
        if (matrix.empty()) return 0;
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<int>> presum(M + 1, vector<int>(N + 1, 0));

        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) {
            presum[i + 1][j + 1] = presum[i + 1][j] + matrix[i][j]; // 按行取前缀和
        }
        
        vector<int> rowbetweenSum(M + 1, 0); 
        for (int i = 0; i < N; i++) for (int j = 0; j <= i; j++) {
            for (int m = 0; m < M; m++) rowbetweenSum[m + 1] = rowbetweenSum[m] + presum[m + 1][i + 1] - presum[m + 1][j];
            for (int k = 1; k < M + 1; k++) for (int l = 0; l < k; l++) {
                if (rowbetweenSum[k] - rowbetweenSum[l] == target) ret++;
            }
        }
        return ret;
    }
};
// @lc code=end

/* Test Main */
int main(void)
{
    Solution solve;
    vector<vector<int>> matrix;
    matrix.push_back({0,1,0});
    matrix.push_back({1,1,1});
    matrix.push_back({0,1,0});
    solve.numSubmatrixSumTarget(matrix, 0);
    return 0;
}
