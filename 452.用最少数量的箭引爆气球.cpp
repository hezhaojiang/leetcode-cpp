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
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (0 == points.size()) return 0;
#if 0
        sort(points.begin(), points.end(), [](const auto &u, const auto &v) { return u[0] <= v[0]; });
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
#endif
        sort(points.begin(), points.end(), [](const auto &u, const auto &v) { return u[1] <= v[1]; });

        int right = points[0][1], shot = 1;

        for (auto p : points) if (p[0] > right) {
            shot++;
            right = p[1];
        }
        return shot;
    }
};
// @lc code=end

