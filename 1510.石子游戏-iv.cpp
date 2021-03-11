/*
 * @lc app=leetcode.cn id=1510 lang=cpp
 *
 * [1510] 石子游戏 IV
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    int n;
    vector<int> memo;
    bool dfs(int i) {
        if (i == 0) return false;
        if (memo[i] != -1) return memo[i] == 1;
        bool canWin = false;
        for (int x = 1; x <= sqrt(i); x++) {
            if (!dfs(i - x * x)) {
                canWin = true;
                break;
            }
        }
        return memo[i] = canWin;
    }

public:
    bool winnerSquareGame(int n) {
        this->n = n;
        memo.resize(n + 1, -1);
        return dfs(n);
    }
};
// @lc code=end
