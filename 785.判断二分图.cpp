/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
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
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> visited(N, 0);
        for (int i = 0; i < N; i++) {
            if (!visited[i] && !dfs(graph, i, 1, visited)) return false;
        }
        return true;
    }
};
// @lc code=end

