/*
 * @lc app=leetcode.cn id=1579 lang=cpp
 *
 * [1579] 保证图可完全遍历
 */
#include <vector>
using namespace std;
// @lc code=start
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    UnionFind(int size) : parent(vector<int>(size)) ,rank(vector<int>(size)) {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        count = size - 1;
    }
    /* 对 Find 函数进行路径压缩优化 */
    int Find(int x) {
        if (parent[x] != x) parent[x] = Find(parent[x]);
        return parent[x];
    }
    /* 对 Union 函数进行按秩合并优化 */
    void Union(int x, int y) {
        int xRoot = Find(x);
        int yRoot = Find(y);
        if (xRoot == yRoot) return;
        count--;
        if (rank[xRoot] < rank[yRoot]) parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot]) parent[yRoot] = xRoot;
        else { parent[yRoot] = xRoot; rank[xRoot]++; }
        return;
    }
    
    int Count(void) {
        return count;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind Alice(n + 1);
        UnionFind Bob(n + 1);
        int deletePath = 0;
        for (auto edge : edges) {
            if (edge[0] == 3) {
                int deleteflag = 0;
                int aroot = Alice.Find(edge[1]);
                int broot = Alice.Find(edge[2]);
                if (aroot == broot) deleteflag++;
                else Alice.Union(aroot, broot);
                aroot = Bob.Find(edge[1]);
                broot = Bob.Find(edge[2]);
                if (aroot == broot) deleteflag++;
                else Bob.Union(aroot, broot);
                if (deleteflag == 2) deletePath++;
            }
        }
        for (auto edge : edges) {
            int deleteflag = 0;
            if (edge[0] == 1) {
                int aroot = Alice.Find(edge[1]);
                int broot = Alice.Find(edge[2]);
                if (aroot == broot) deleteflag++;
                else Alice.Union(aroot, broot);
            }
            if (edge[0] == 2) {
                int aroot = Bob.Find(edge[1]);
                int broot = Bob.Find(edge[2]);
                if (aroot == broot) deleteflag++;
                else Bob.Union(aroot, broot);
            }
            if (deleteflag != 0) deletePath++;
        }
        if (Bob.Count() != 1 || Alice.Count() != 1) return -1;
        else return deletePath;
    }
};
// @lc code=end

