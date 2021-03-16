/*
 * @lc app=leetcode.cn id=935 lang=cpp
 *
 * [935] 骑士拨号器
 */
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
#define MOD ((int)1e9 + 7)
class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> graph{{4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
                                  {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        vector<int> dp(10, 1);  // 初始跳了 0 步 骑士的位置有 10 种 每种有一种排列
        for (int i = 1; i < n; i++) {
            vector<int> dptemp(10, 0);
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < graph[j].size(); k++) {
                    dptemp[graph[j][k]] = (0LL + dp[j] + dptemp[graph[j][k]]) % MOD;
                }
            }
            dp = dptemp;
        }
        int res = 0;
        for (int i = 0; i < 10; i++) res = (0LL + res + dp[i]) % MOD;
        return res;
    }
};
// @lc code=end
