/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 *
 * [1155] 掷骰子的N种方法
 */
#include <vector>
using namespace std;
// @lc code=start
#define MOD ((int)1e9 + 7)
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= d; i++) {
            for (int j = target; j >= 0; j--) {
                dp[j] = 0;
                for (int k = min(f, j); k > 0; k--) {
                    dp[j] = (dp[j] + dp[j - k]) % MOD;
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end
