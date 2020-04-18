/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        if(coins.empty()) return -1;
        vector<int> dollar;
        dollar.emplace_back(1);
        for(int money = 1; money <= amount; money ++)
        {
            int method = -1;
            for(auto need : coins)
            {
                
                if(money - need > 0 && dollar[money - need] != -1)
                {
                    if(method == -1) method = dollar[money - need] + 1;
                    else method = min(method, dollar[money - need] + 1);
                } 
                else if(money == need) 
                {
                    method = 1;
                    break;
                }
            }
            dollar.emplace_back(method);
        }
        return dollar[amount];
    }
};
// @lc code=end

