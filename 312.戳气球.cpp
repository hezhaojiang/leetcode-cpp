/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> dp;  // dp[i][j] 表示开区间 (i,j) 内你能拿到的最多金币
    vector<int> val;
    int dfs(int l, int r) {
        if (dp[l][r] != 0) return dp[l][r];
        if (l > r - 2) return 0;
        for (int k = l + 1; k < r; k++) {
            int time = val[l] * val[r];
            dp[l][k] = dfs(l, k);
            dp[k][r] = dfs(k, r);
            dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + val[k] * time);
        }
        return dp[l][r];
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        val.resize(n + 2);
        for (int i = 1; i <= n; i++) val[i] = nums[i - 1];
        val[0] = val[n + 1] = 1;
        dp.resize(n + 2, vector<int>(n + 2, 0));
        return dfs(0, n + 1);
    }
};
// @lc code=end
