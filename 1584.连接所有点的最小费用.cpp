/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
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
    void Union(int a, int b) {
        int rootA = Find(a), rootB = Find(b);
        if (rootA != rootB) {
            count--;
            parent[rootA] = rootB;
        }
    }
    int Count() { return count; }
};

struct Edge {
    int len, x, y;
    Edge(int len, int x, int y) : len(len), x(x), y(y) {};
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto caldist = [&](int i, int j) -> int {
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        };
        int N = points.size();
        UnionFind uf(N);
        vector<Edge> edges;
        for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) {
            edges.emplace_back(caldist(i, j), i, j);
        }
        int cost = 0;
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) { return a.len < b.len; });
        for (auto & edge : edges) {
            if (uf.Find(edge.x) == uf.Find(edge.y)) continue;
            uf.Union(edge.x, edge.y);
            cost += edge.len;
            if (uf.Count() == 1) return cost;
        }
        return 0;
    }
};
// @lc code=end

/* Test Main */
int main(void)
{
    Solution solve;
    vector<vector<int>> points{{0,0},{2,2},{3,10},{5,2},{7,0}};
    solve.minCostConnectPoints(points);
    return 0;
}
