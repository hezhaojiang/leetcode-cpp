/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        int num = 1;
        int nextsq = 1;
        int nextec = nextsq * nextsq;
        vector<int> dp;
        for (int num = 1; num <= n; num++) {
            if (nextec == num) {
                dp.push_back(1);
                nextsq++;
                nextec = nextsq * nextsq;
            }
            else {
                int minCount = INT_MAX;
                for(int i = 1; i < nextsq; i++) {
                    minCount = min(minCount, dp[num-i*i-1] + 1);
                }
                dp.push_back(minCount);
            }
        }
        return dp.back();
    }
};
// @lc code=end

