/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
#if 0
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) { return u[0] < v[0]; });
        int n = intervals.size();
        vector<int> f(n, 1); // 以区间 i 为最后一个区间，可以选出的区间数量的最大值
        for (int i = 1; i < n; ++i) for (int j = 0; j < i; ++j) {
            if (intervals[j][1] <= intervals[i][0]) f[i] = max(f[i], f[j] + 1);
        }
        return n - *max_element(f.begin(), f.end());
#endif
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) { return u[1] < v[1]; });
        int right = intervals[0][1], remain = 1;
        for (int i = 1; i < intervals.size(); i++ ) {
            if (intervals[i][0] >= right) {
                remain++;
                right = intervals[i][1];
            }
        }
        return intervals.size() - remain;
    }
};
// @lc code=end

