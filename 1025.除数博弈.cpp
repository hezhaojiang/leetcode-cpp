/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 *
 * [1025] 除数博弈
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> memo; // memo[i] = 1 代表黑板上是数字 i 先手能赢
    bool dfs(int n) {
        if (n == 1) return false;
        if (memo[n] != -1) return memo[n] == 1;
        bool canWin = false;
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0 && !dfs(n - i)) {
                canWin = true;
                break;
            }
        }
        return memo[n] = canWin;
    }

public:
    bool divisorGame(int N) {
        memo.resize(N + 1, -1);
        return dfs(N);
    }
};
// @lc code=end
