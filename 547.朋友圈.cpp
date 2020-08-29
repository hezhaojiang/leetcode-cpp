/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */
#include<vector>
using namespace std;
// @lc code=start
class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;
    int count;
public:
    UnionFind(int size) : parent(std::vector<int>(size)) ,rank(std::vector<int>(size)) {
        count = size;
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    void MakeSet(int x) {
        if (x < parent.size()) parent[x] = x;
        else {
            int osize = parent.size();
            count += x + 1 - osize;
            parent.resize(x + 1);
            rank.resize(x + 1);
            for (int i = osize; i <= x; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }
        return;
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
        count--;
        return;
    }
    int getRootCount() {
        return count;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.size() <= 0) return 0;
        if (M[0].size() <= 1) return M[0].size();
        UnionFind uf(M[0].size());
        for (auto & m : M) {
            int lastRoot = -1;
            for (int i = 0; i < m.size(); i++) {
                if (m[i] == 1) {
                    int currRoot = uf.Find(i);
                    if (lastRoot != -1) uf.Union(lastRoot, currRoot);
                    lastRoot = currRoot;
                }
            }
        }
        return uf.getRootCount();
    }
};
// @lc code=end

