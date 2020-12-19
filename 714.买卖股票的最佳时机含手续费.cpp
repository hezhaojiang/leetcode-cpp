/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> upStk;
        int earnMoney = 0;
        for (auto a : prices) {
            if (!upStk.empty() && upStk.back() > a) {
                if (a > upStk.front() && upStk.back() <= a + fee) continue;
                earnMoney += max(0, upStk.back() - upStk.front() - fee);
                upStk.clear();
            }
            upStk.push_back(a);
        }
        earnMoney += max(0, upStk.back() - upStk.front() - fee);
        return earnMoney;
    }
};
// @lc code=end

