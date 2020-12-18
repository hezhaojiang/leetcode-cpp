/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if (N == 0) return 0;
        vector<int> dp1(N), dp2(N);

        vector<int> upStk;
        int maxMoney = 0;
        for (int i = 0; i < N; i++) {
            while(!upStk.empty() && upStk.back() > prices[i]) upStk.pop_back();
            upStk.push_back(prices[i]);
            maxMoney = max(maxMoney, upStk.back() - upStk.front());
            dp1[i] = maxMoney;
        }

        vector<int> downStk;
        maxMoney = 0;
        for (int i = N - 1; i >= 0; i--) {
            while(!downStk.empty() && downStk.back() < prices[i]) downStk.pop_back();
            downStk.push_back(prices[i]);
            maxMoney = 0 - max(-maxMoney, downStk.front() - downStk.back());
            dp2[i] = -maxMoney;
        }

        maxMoney = 0;
        for (int i = 0; i< N; i++) maxMoney = max(maxMoney, dp1[i] + dp2[i]);
        return maxMoney;
    }
};
// @lc code=end

