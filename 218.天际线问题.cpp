/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        /* 所有坐标小根堆 */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> allpoint;
        multiset<int> heights{0};
        vector<int> point(2, 0);
        vector<vector<int>> result;

        for (auto& building : buildings) {
            /* 左侧节点的高度用负数 */
            /* 如果右侧节点用负数, 则会导致在横坐标相同时, 先弹出右坐标, 再插入左坐标 */
            allpoint.push(pair<int, int>(building[0], 0 - building[2]));
            allpoint.push(pair<int, int>(building[1], building[2]));
        }

        while (!allpoint.empty()) {
            if (allpoint.top().second < 0) heights.insert(0 - allpoint.top().second);
            /* heights.erase(allpoint.top().second) 会把所有 allpoint.top().second 值都会清除掉 */
            else
                heights.erase(heights.find(allpoint.top().second));

            if (point[1] != *heights.rbegin()) {
                point[0] = allpoint.top().first;
                point[1] = *heights.rbegin();
                result.push_back(point);
            }
            allpoint.pop();
        }
        return result;
    }
};
// @lc code=end
