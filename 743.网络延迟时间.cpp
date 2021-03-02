/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * {743] }
 */
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
struct Target {
    int pos;
    int time;
    Target(int p = 0, int t = 0) : pos(p), time(t) {}
    bool operator<(const Target& a) const { return time > a.time; }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
#define USE_DIJKSTRA

#ifdef USE_DIJKSTRA
        vector<vector<int>> edges(n + 1);
        for (int i = 0; i < times.size(); i++) {
            edges[times[i][0]].push_back(i);
        }
        priority_queue<Target> Q;
        vector<int> cost(n + 1, INT_MAX);
        vector<int> visited(n + 1, 0);
        Q.push(Target{k, 0});

        while (!Q.empty()) {
            Target t = Q.top();
            Q.pop();
            if (!visited[t.pos]) {
                cost[t.pos] = t.time;
                for (auto& index : edges[t.pos]) {
                    if (!visited[times[index][1]]) {
                        Q.push(Target{times[index][1], times[index][2] + t.time});
                    }
                }
                visited[t.pos] = 1;
            }
        }
        int res = *max_element(cost.begin() + 1, cost.end());
        return res == INT_MAX ? -1 : res;
#endif

#ifdef USE_FLOYD_WARSHALL
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++) cost[i][i] = 0;
        for (auto& t : times) cost[t[0] - 1][t[1] - 1] = t[2];
        for (int m = 0; m < n; m++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cost[i][j] = min(cost[i][j], cost[i][m] + cost[m][j]);
                }
            }
        }
        int res = *max_element(cost[k - 1].begin(), cost[k - 1].end());
        return res == INT_MAX / 2 ? -1 : res;
#endif
    }
};
// @lc code=end

int main() {
    Solution solve;
    vector<vector<int>> times{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    solve.networkDelayTime(times, 4, 2);
    return 0;
}
