/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), // 宽度从小到大 高度从大到小
            [](auto& a, auto& b) { return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]); });
        // 以下为 LIS 最长上升子序列问题
        vector<int> dp;
        for(const auto& e: envelopes) {
            auto p = lower_bound(dp.begin(), dp.end(), e[1]);
            if(p == dp.end()) dp.push_back(e[1]);
            else *p = e[1];
        }
        return dp.size();
    }
};
// @lc code=end

