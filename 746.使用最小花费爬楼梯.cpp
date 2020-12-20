/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.empty()) return 0;
        cost.push_back(0);
        int N = cost.size();
        vector<int> dp(N + 1, 0);
        dp[1] = cost[0];
        for (int i = 1; i < N; i++)
            dp[i + 1] = min(dp[i], dp[i - 1]) + cost[i];
        return dp[N];
    }
};
// @lc code=end

