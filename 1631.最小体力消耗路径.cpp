/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int Find(int n) {
        return n == parent[n] ? n : parent[n] = Find(parent[n]);
    }
    void Union(int a, int b) {
        int rootA = Find(a), rootB = Find(b);
        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) swap(rootA, rootB);
            parent[rootA] = rootB;
            if (rank[rootA] == rank[rootB]) rank[rootB]++;
        }
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> edges;
        int rows = heights.size();
        int columns = heights[0].size();
        for (int i = 0; i < rows; i++) for (int j = 0; j < columns; j++) {
            int id = i * columns + j;
            if (i < rows - 1) edges.push_back({id, id + columns, abs(heights[i][j] - heights[i + 1][j])});
            if (j < columns - 1) edges.push_back({id, id + 1, abs(heights[i][j] - heights[i][j + 1])});
        }
        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b){ return a[2] < b[2]; });
        int len = rows * columns;
        UnionFind uf(len);
        for (int i = 0; i < edges.size(); i++) {
            uf.Union(edges[i][0], edges[i][1]);
            if (uf.Find(0) == uf.Find(len - 1)) return edges[i][2];
        }
        return 0;
    }
};
// @lc code=end

