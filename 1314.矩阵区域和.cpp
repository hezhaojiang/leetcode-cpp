/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        if (mat.empty()) return {};
        int M = mat.size();
        int N = mat[0].size();
        vector<vector<int>> presum(M + 1, vector<int>(N + 1, 0));

        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) {
            presum[i + 1][j + 1] = presum[i + 1][j] + presum[i][j + 1] - presum[i][j] + mat[i][j];
        }

        vector<vector<int>> ret(M, vector<int>(N, 0));
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) {
            int rdx = min(i + K + 1, M); // 右下角 rdx
            int rdy = min(j + K + 1, N);
            int lux = max(0, i - K);
            int luy = max(0, j - K);
            ret[i][j] = presum[rdx][rdy] + presum[lux][luy] - presum[rdx][luy] - presum[lux][rdy];
        }
        return ret;
    }
};
// @lc code=end

