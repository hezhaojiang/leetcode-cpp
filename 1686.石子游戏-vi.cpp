/*
 * @lc app=leetcode.cn id=1686 lang=cpp
 *
 * [1686] 石子游戏 VI
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> index(n, 0);
        for (int i = 0; i < n; i++) index[i] = i;
        sort(index.begin(), index.end(),
             [&](auto& i, auto& j) { return aliceValues[i] + bobValues[i] > aliceValues[j] + bobValues[j]; });
        int alice = 0, bob = 0;
        for (int i = 0; i < n; i += 2) {
            alice += aliceValues[index[i]];
            if (i + 1 < n) bob += bobValues[index[i + 1]];
        }
        if (alice > bob) return 1;
        else if (alice < bob) return -1;
        else return 0;
    }
};
// @lc code=end
