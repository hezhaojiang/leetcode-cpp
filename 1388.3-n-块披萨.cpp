/*
 * @lc app=leetcode.cn id=1388 lang=cpp
 *
 * [1388] 3n 块披萨
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int calculate(const vector<int>& slices, int start, int end) {
        int N = end - start + 1;
        int choose = (N + 1) / 3;
        /* dp 表示在 N 个数中选择 choose 个数的最大和 */
        vector<vector<int>> dp(N + 1, vector<int>(choose + 1, 0));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= choose && j <= i; ++j) {
                dp[i][j] = max(dp[i - 1][j], /* 没有选择该数字 最大和与上一个数字相同 */
                    (i - 2 >= 0 ? dp[i - 2][j - 1] : 0) + slices[start + i - 1]); /* 选择了该数字，前一个数字不能选择 */
            }
        }
        return dp[N][choose];
    }
    int maxSizeSlices(vector<int>& slices) {
        int N = slices.size();
        int res1 = calculate(slices, 0, N - 2);
        int res2 = calculate(slices, 1, N - 1);
        return max(res1, res2);
    }
};
// @lc code=end

