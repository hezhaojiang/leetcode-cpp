/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int size = piles.size();
        /* dp[i][j] 代表在 piles[i]~piles[j] 之间，先手比后手多的石子数 */
        auto dp = vector<vector<int>>(size, vector<int>(size));
        for (int i = 0; i < size; i++) dp[i][i] = piles[i];
        /* dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]) */
        for (int i = size - 2; i >= 0; i--) for (int j = i + 1; j < size; j++) 
            dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
        return dp[0][size - 1] > 0;
    }
};
// @lc code=end
