/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        count = n;
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int Find(int n) {
        return n == parent[n] ? n : parent[n] = Find(parent[n]);
    }
    int Count() { return count; };
    void Union(int a, int b) {
        int rootA = Find(a), rootB = Find(b);
        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) swap(rootA, rootB);
            parent[rootA] = rootB;
            if (rank[rootA] == rank[rootB]) rank[rootB]++;
            count--;
        }
    }
};
public:
    int minSwapsCouples(vector<int>& row) {
        int N = row.size() / 2;
        UnionFind uf(N);
        for (int i = 0; i < row.size(); i += 2) {
            uf.Union(row[i] / 2, row[i + 1] / 2);
        }
        return N - uf.Count();
    }
};
// @lc code=end

