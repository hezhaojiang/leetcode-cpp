/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> result;
    int dp(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        if (result[amount] != 0) return result[amount];

        int method = INT_MAX;
        for (auto need : coins) {
            int tempmethod = dp(coins, amount - need);
            if (tempmethod >= 0 && method > tempmethod + 1) method = tempmethod + 1;
        }
        result[amount] = (method == INT_MAX ? -1 : method);
        return result[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        result.resize(amount + 1);
        return dp(coins, amount);
    }
};
// @lc code=end
