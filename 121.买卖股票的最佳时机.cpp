/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<int> upStk;
        int maxMoney = 0;
        for(auto a : prices){
            while(!upStk.empty() && upStk.back() > a) upStk.pop_back();
            upStk.push_back(a);
            maxMoney = max(maxMoney, upStk.back() - upStk.front());
        }
        return maxMoney;
    }
};
// @lc code=end

