/*
 * @lc app=leetcode.cn id=903 lang=cpp
 *
 * [903] DI 序列的有效排列
 */
#include <numeric>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
#define MOD ((int)1e9 + 7)
class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.length();
        // dp[i][j] 表示由范围 [0, i] 内的数字组成且最后一个数字为 j 的不同序列的个数
        vector<vector<int>> dp(n + 1, vector(n + 1, 0));
        dp[0][0] = 1;  // 范围 [0, 0] 且最后一位数字为 0 的序列个数为 1 序列为 (0)
                       // 由 dp[i][j] 定义可知 i 要大于等于 j
        // 当是降序时，下一个数字不小于当前最后一个数字
        // 当是升序时，下一个数字小于当前最后一个数字，所以可以写出状态转移方程如下所示：
        // if (S[i-1] == 'D')    dp[i][j] += dp[i-1][k]    ( j <= k <= i-1 )
        // else                  dp[i][j] += dp[i-1][k]    ( 0 <= k < j )
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; ++j) {
                if (S[i - 1] == 'D') {
                    for (int k = j; k <= i - 1; ++k) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                    }
                } else {
                    for (int k = 0; k <= j - 1; ++k) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= n; ++i) {
            res = (res + dp[n][i]) % MOD;
        }
        return res;
    }
};
// @lc code=end
