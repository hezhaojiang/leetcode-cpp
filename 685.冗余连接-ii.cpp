/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */
#include<vector>
using namespace std;
// @lc code=start
class UnionFind {
private:
    std::vector<int> parent;
public:
    UnionFind(int size) : parent(std::vector<int>(size)) {
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    int Parent(int x) {
        return parent[x];
    }

    int Find(int x) {
        if (parent[x] != x) return Find(parent[x]);
        else return x;
    }
    void Union(int x, int y) {
        parent[y] = x;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n + 1);
        int noCircle = 1;
        vector<int> CircleEdge;
        vector<vector<int>> twoDegreeEdge;
        for (auto edge : edges) {
            int rootp = uf.Find(edge[0]);
            int rootq = uf.Find(edge[1]);
            if (rootq != edge[1]) {            /* 出现有两个入度的边 */
                twoDegreeEdge.push_back(vector<int>{uf.Parent(edge[1]), edge[1]});
                twoDegreeEdge.push_back(edge);
            }
            else if (rootp == rootq) CircleEdge = edge;  /* 出现环 */
            else uf.Union(edge[0], edge[1]);
        }
        /* 注意 触发出现入度为 2 的顶点的边 和 触发环出现的边没有入并查集 */
        
        /* 如果不存在入度为 2 的顶点，则触发环的边为附件边 */
        if (twoDegreeEdge.empty()) return CircleEdge;

        /* 如果不存在环，则触发出现入度为 2 的顶点的边为附加边 */
        if (CircleEdge.empty()) return twoDegreeEdge[1];

        /* 如果既有环又有入度为 2 的顶点 
         * 说明入度为 2 的顶点的另一条边（非触发该点入度为 2 的边）即导致了该点入度增加，又导致了环的出现 */
        return twoDegreeEdge[0];
    }
};
// @lc code=end

