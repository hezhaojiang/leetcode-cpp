/*
 * @lc app=leetcode.cn id=1489 lang=cpp
 *
 * [1489] 找到最小生成树里的关键边和伪关键边
 */
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class UnionFind {
private:
    vector<int> parent;
    int count;
public:
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int Find(int n) {
        return n == parent[n] ? n : parent[n] = Find(parent[n]);
    }
    bool Union(int a, int b) {
        int rootA = Find(a), rootB = Find(b);
        if (rootA != rootB) {
            count--;
            parent[rootA] = rootB;
            return true;
        } else return false;
    }
    int Count() { return count; }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int N = edges.size();
        // 记录 edges 索引号
        for (int i = 0; i < N; i++) edges[i].push_back(i);
        // 计算最小生成树权值
        sort(edges.begin(), edges.end(), [](auto &a, auto &b){ return a[2] < b[2]; });
        int value = 0;
        UnionFind ufmin(n);
        for (auto &edge : edges) {
            if (ufmin.Union(edge[0], edge[1])) value += edge[2];
        }
        if (ufmin.Count() != 1) return {}; // 无法连通 生成最小生成树
        // 遍历检查每条边
        vector<vector<int>> res(2);
        for (int i = 0; i < N; i++) {
            // 检查当前边是否是关键边
            int v = 0;
            UnionFind uf_key(n);
            for (int j = 0; j < N; j++) {
                if (i != j && uf_key.Union(edges[j][0], edges[j][1])) v += edges[j][2];
            }
            if (uf_key.Count() != 1 || v != value) {
                res[0].push_back(edges[i][3]);
                continue; // 是关键边 一定不是伪关键边
            }

            // 检查当前边是否是伪关键边
            v = edges[i][2];
            UnionFind uf_nkey(n);
            uf_nkey.Union(edges[i][0], edges[i][1]);
            for (int j = 0; j < N; j++) {
                if (i != j && uf_nkey.Union(edges[j][0], edges[j][1])) v += edges[j][2];
            }
            if (v == value) res[1].push_back(edges[i][3]);
        }
        return res;
    }
};
// @lc code=end

/* Test Main */
int main(void)
{
    Solution solve;
    vector<vector<int>> edges{{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};
    solve.findCriticalAndPseudoCriticalEdges(5, edges);
    return 0;
}
