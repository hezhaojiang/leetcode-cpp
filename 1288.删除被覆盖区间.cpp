/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) { return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]); });
        int remove = 0, end = 0;
        for (auto& i : intervals) {
            if (i[1] <= end) remove++;
            else end = i[1];
        }
        return intervals.size() - remove;
    }
};
// @lc code=end
