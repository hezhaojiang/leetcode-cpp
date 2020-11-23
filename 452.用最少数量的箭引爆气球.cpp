/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
bool cmp(vector<int>& a, vector<int> b) {
    return a.front() > b.front() ? false : true;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (0 == points.size()) return 0;
        sort(points.begin(), points.end(), cmp);
        struct {
            int begin;
            int end;
            int number;
        } shotfield;

        shotfield.begin = points[0][0];
        shotfield.end = points[0][1];
        shotfield.number = 1;

        for (auto p : points) {
            if (p[0] > shotfield.end) {
                shotfield.number++;
                shotfield.begin = p[0];
                shotfield.end = p[1];
            }
            else if (p[1] < shotfield.end) shotfield.end = p[1];
        }
        return shotfield.number;
    }
};
// @lc code=end

