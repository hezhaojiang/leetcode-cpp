/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    bool dfs(vector<vector<int>>& graph, int index, int color, vector<int>& vis) {
        if (vis[index] != 0) return vis[index] == color;
        vis[index] = color;
        for (int i = 0; i < graph[index].size(); i++) {
            if (!dfs(graph, graph[index][i], -color, vis)) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N, vector<int>{});
        for (auto &dlike : dislikes) {
            graph[dlike[0] - 1].push_back(dlike[1] - 1);
            graph[dlike[1] - 1].push_back(dlike[0] - 1);
        }
        vector<int> visited(N, 0);
        for (int i = 0; i < N; i++) {
            if (!visited[i] && !dfs(graph, i, 1, visited)) return false;
        }
        return true;
    }
};
// @lc code=end

