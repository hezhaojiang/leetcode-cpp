/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int getMexLessKRecursive(vector<int>& sum, int upper, int left, int right) {
        if (left == right) return INT_MIN;
        int mid = (left + right) / 2;
        int n1 = getMexLessKRecursive(sum, upper, left, mid);
        int n2 = getMexLessKRecursive(sum, upper, mid + 1, right);
        int ret = max(n1, n2);

        // 找到最大前缀和之差 且不大于 upper
        for (int l = left, r = mid + 1; l <= mid; l++)
            // 这里是 O(n) 而不是 O(n^2) 因为 r 的值每次不会重头开始
            while (r <= right && sum[r] - sum[l] <= upper) 
                ret = max(ret, sum[r++] - sum[l]);

        // 随后合并两个排序数组
        vector<int> sorted(right - left + 1);
        int m, n, p;
        for (m = left, n = mid + 1, p = 0; m <= mid && n <= right; p++) {
            if (sum[m] < sum[n]) sorted[p] = sum[m++];
            else sorted[p] = sum[n++];
        }
        while (m <= mid) sorted[p++] = sum[m++];
        while (n <= right) sorted[p++] = sum[n++];
        for (int i = 0; i < sorted.size(); i++) sum[left + i] = sorted[i];
        return ret;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int M = matrix.size();
        if (M == 0) return {};
        int N = matrix[0].size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        dp[1][1] = matrix[0][0];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                dp[i + 1][j + 1] = matrix[i][j] + dp[i + 1][j]; // 行前缀和
            }
        }

        int maxMatrix = INT_MIN;
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
        for (c1 = 0; c1 < N; c1++) {        // 按行便利 行左边界
            for (c2 = c1; c2 < N; c2++) {   // 按行便利 行右边界
                vector<int> dprow(M + 1, 0);// 行左右边界的和
                for (int i = 0; i < M; i++) dprow[i + 1] = dp[i + 1][c2 + 1] - dp[i + 1][c1];
                for (int i = 0; i < M; i++) dprow[i + 1] += dprow[i]; // dprow 已是前缀和
                /* 找到最大前缀和差 且不超过 k */
                maxMatrix = max(maxMatrix, getMexLessKRecursive(dprow, k, 0, M));
            }
        }
        return maxMatrix; 
    }
};
// @lc code=end

/* Test Main */
int main(void)
{
    Solution solve;
    vector<vector<int>> matrix;
    //matrix.push_back({1,0,1});
    //matrix.push_back({0,-2,3});
    //solve.maxSumSubmatrix(matrix, 2);

    matrix.push_back({2,2,-1});
    solve.maxSumSubmatrix(matrix, 0);

    //matrix.push_back({5,-4,-3,4});
    //matrix.push_back({-3,-4,4,5});
    //matrix.push_back({5,1,5,-4});
    
    solve.maxSumSubmatrix(matrix, 8);
    return 0;
}
