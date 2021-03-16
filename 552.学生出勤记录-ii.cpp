/*
 * @lc app=leetcode.cn id=552 lang=cpp
 *
 * [552] 学生出勤记录 II
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
#define MOD ((int)1e9 + 7)
typedef long long llint;
class Solution {
public:
    int checkRecord(int n) {
        // dp[i][j] 代表缺勤了 i 次，连续迟到了 j 次出勤记录数量
        vector<vector<llint>> dp(2, vector<llint>(3, 0));
        vector<vector<llint>> dptemp(2, vector<llint>(3, 0));
        dp[0][0] = 1; // 字符串长度为 0 时，一定是 0 缺勤 0 迟到
        for (int i = 1; i <= n; i++) {
#if 0
            // 缺勤（缺勤后迟到会降低到 0）
            for (int j = 0; j < 3; j++) dptemp[1][0] = (dptemp[1][0] + dp[0][j]) % MOD;
            for (int j = 0; j < 2; j++) {
                // 迟到
                for (int k = 0; k < 2; k++) dptemp[j][k + 1] = (dptemp[j][k + 1] + dp[j][k]) % MOD;
                // 到场
                for (int k = 0; k < 3; k++) dptemp[j][0] = (dptemp[j][0] + dp[j][k]) % MOD;
            }
#endif
            dptemp[0][0] = (dp[0][0] + dp[0][1] + dp[0][2]) % MOD;;
            dptemp[0][1] = dp[0][0];
            dptemp[0][2] = dp[0][1];
            dptemp[1][0] = (dp[0][0] + dp[0][1] + dp[0][2] + dp[1][0] + dp[1][1] + dp[1][2]) % MOD;
            dptemp[1][1] = dp[1][0];
            dptemp[1][2] = dp[1][1];
            dp = dptemp;
        }
        int res = 0;
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 3; k++) res = (res + dp[j][k]) % MOD;
        return res;
    }
};
// @lc code=end

int main()
{
    Solution solve;
    solve.checkRecord(4);
    return 0;
}
