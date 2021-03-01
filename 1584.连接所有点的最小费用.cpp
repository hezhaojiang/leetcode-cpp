/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto caldist = [&](int i, int j) -> int {
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        };
        int N = points.size();
        vector<vector<int>> edges(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++) {
                edges[i][j] = edges[j][i] = caldist(i, j);
            }
        vector<int> distance(N, INT_MAX), visited(N, 0);
        distance[0] = 0;
        for (int i = 0; i < N; i++) {
            int next = -1;
            for (int j = 0; j < N; j++) {
                if (!visited[j] && (next == -1 || distance[j] < distance[next])) next = j;
            }
            visited[next] = true;
            for (int k = 0; k < N; k++) {
                if (!visited[k]) distance[k] = min(distance[k], edges[next][k]);
            }
        }
        return accumulate(distance.begin(), distance.end(), 0);
    }
};
// @lc code=end

/* Test Main */
int main(void) {
    Solution solve;
    vector<vector<int>> points{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    solve.minCostConnectPoints(points);
    return 0;
}
