/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */
#include<vector>
using namespace std;
// @lc code=start
class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:
    UnionFind(int size) : parent(std::vector<int>(size)) ,rank(std::vector<int>(size)) {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    void MakeSet(int x) {
        if (x < parent.size()) parent[x] = x;
        else {
            int osize = parent.size();
            parent.resize(x + 1);
            rank.resize(x + 1);
            for (int i = osize; i <= x; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }
    }
    int Find(int x) {
        if (parent[x] != x) parent[x] = Find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y) {
        int xRoot = Find(x);
        int yRoot = Find(y);
        if (xRoot == yRoot) return;
        if (rank[xRoot] < rank[yRoot]) parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot]) parent[yRoot] = xRoot;
        else { parent[yRoot] = xRoot; rank[xRoot]++; }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n + 1);
        for(int i = 0; i < n; i++){
            int rootp = uf.Find(edges[i][0]);
            int rootq = uf.Find(edges[i][1]);
            if(rootp == rootq) return edges[i];
            uf.Union(rootp, rootq);
        }
        return {};
    }
};
// @lc code=end
