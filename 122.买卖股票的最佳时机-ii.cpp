/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> upStk;
        int earnMoney = 0;
        for (auto a : prices) {
            if (!upStk.empty() && upStk.back() > a) {
                earnMoney += upStk.back() - upStk.front();
                upStk.clear();
            }
            upStk.push_back(a);
        }
        earnMoney += upStk.back() - upStk.front();
        return earnMoney;
    }
};
// @lc code=end

