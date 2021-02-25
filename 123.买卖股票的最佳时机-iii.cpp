/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        // None 未进行过任何操作
        int buy_one = -prices[0];   // 只进行过一次买操作
        int sale_one = 0;           // 进行了一次买操作和一次卖操作，即完成了一笔交易
        int buy_two = -prices[0];   // 在完成了一笔交易的前提下，进行了第二次买操作
        int sale_all = 0;           // 完成了全部两笔交易
        for (int i = 0; i < n; i++) {
            sale_all = max(sale_all, buy_two + prices[i]);
            buy_two  = max(buy_two, sale_one - prices[i]);
            sale_one = max(sale_one, buy_one + prices[i]);
            buy_one  = max(buy_one, - prices[i]);
        }
        return max(sale_all, sale_one);
    }
};
// @lc code=end

int main()
{
    Solution solve;
    vector<int> prices{2,1,4,5,2,9,7};
    solve.maxProfit(prices);
    return 0;
}