/*
 * @lc app=leetcode.cn id=834 lang=cpp
 *
 * [834] 树中距离之和
 */

// @lc code=start
class Solution {
public:
    vector<int> g[10005];
    vector<int> res;
    int dp[10005], sz[10005];

    void dfs1(int u, int fa) {
        sz[u] = 1;
        dp[u] = 0;
        for (auto v: g[u]) {
            if (v == fa) continue;
            dfs1(v, u);
            sz[u] += sz[v];
            dp[u] += dp[v] + sz[v];
        }
    }

    void dfs2(int u, int fa) {
        res[u] = dp[u];
        for (auto v: g[u]) {
            if (v == fa) continue;
            int du = dp[u], dv = dp[v];
            int su = sz[u], sv = dp[v];
            dp[u] -= dp[v] + sz[v];
            sz[u] -= sz[v];
            dp[v] += dp[u] + sz[u];
            sz[v] += sz[u];
            dfs2(v, u);
            dp[u] = du, dp[v] = dv;
            sz[u] = su, sz[v] = sv;
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        for (auto edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        res.resize(N, 0);
        dfs1(0, -1);
        dfs2(0, -1);
        return res;
    }
};
// @lc code=end

