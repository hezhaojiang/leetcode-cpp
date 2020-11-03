/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i;
        for (i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] < newInterval[0]) result.push_back(intervals[i]);
            else break;
        }
        result.push_back(newInterval);
        if (i < intervals.size()) result.back()[0] = min(result.back()[0], intervals[i][0]);
        for (; i < intervals.size(); ++i) {
            if (result.back()[1] < intervals[i][0]) result.push_back(intervals[i]);
            else result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
        return result;
    }
};
// @lc code=end

