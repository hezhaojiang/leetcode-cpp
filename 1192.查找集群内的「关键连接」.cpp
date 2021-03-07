/*
 * @lc app=leetcode.cn id=1192 lang=cpp
 *
 * [1192] 查找集群内的「关键连接」
 */
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 强连通分量v
 * 对于图 G，若存在一条途径使得结点 u 走到到结点 v，则称 u 和 v 是 连通的
 * 强连通的定义是：有向图 G 强连通是指，G 中任意两个结点连通。
 * 强连通分量（Strongly Connected Components，SCC）的定义是：极大的强连通子图
 * https://www.cnblogs.com/nullzx/p/7968110.html
 */
// @lc code=start
class Solution {
private:
    vector<vector<int>> graph;
    vector<int> dfn, low;
    vector<bool> visit;
    vector<vector<int>> res;
    void dfs_tarjan(int node, int parent, int step) {
        dfn[node] = low[node] = step;
        visit[node] = true;
        for (auto e : graph[node]) {
            if (e == parent) continue;
            if (!visit[e]) {
                dfs_tarjan(e, node, step + 1);
                low[node] = min(low[e], low[node]);
                if (low[e] > dfn[node]) res.push_back({node, e});
            } else
                low[node] = min(low[node], dfn[e]);
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // 1. 建图 邻接表
        graph.resize(n, vector<int>{});
        for (auto& c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        // 2. Tarjan 算法
        dfn.resize(n, 0);
        low.resize(n, 0);
        visit.resize(n, false);
        dfs_tarjan(0, -1, 0);
        return res;
    }
};
// @lc code=end
