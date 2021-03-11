/*
 * @lc app=leetcode.cn id=1406 lang=cpp
 *
 * [1406] 石子游戏 III
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    int n;
    vector<int> memo;
    int dfs(vector<int>& stoneValue, int start) {
        if (start == n) return 0;
        if (memo[start] != INT_MAX) return memo[start];
        int earn = 0, score = INT_MIN;
        for (int i = start; i < min(start + 3, n); i++) {
            earn += stoneValue[i];
            score = max(score, earn - dfs(stoneValue, i + 1));
        }
        return memo[start] = score;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memo.resize(n, INT_MAX);
        dfs(stoneValue, 0);
        if (memo[0] > 0) return "Alice";
        else if (memo[0] < 0) return "Bob";
        else return "Tie";
    }
};
// @lc code=end
