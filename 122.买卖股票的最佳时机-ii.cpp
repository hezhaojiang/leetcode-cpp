/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        prices.push_back(0);
        int buy = prices.front();
        bool inc = false;
        int profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(!inc && prices[i-1] < prices[i]) {buy = prices[i-1]; inc = true;}
            if(inc && prices[i-1] > prices[i]) {profit += prices[i-1] - buy; inc = false;}
        }
        return profit;
    }
};
// @lc code=end

