/*
 * @lc app=leetcode.cn id=1319 lang=cpp
 *
 * [1319] 连通网络的操作次数
 */
#include<vector>
using namespace std;
// @lc code=start
class UnionFind {
private:
    vector<int> f;
    int count;
public:
    UnionFind(int num) {
        f.resize(num);
        count = num;
        for (int i = 0; i < num; i++) f[i] = i;
    }
    int Count() { return count; }
    int Find(int a) { return a == f[a] ? a : f[a] = Find(f[a]); }
    void Union(int a, int b) {
        int fa = Find(a);
        int fb = Find(b);
        if (fa != fb) { f[fa] = fb; count--; }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() + 1 < n) return -1;
        UnionFind uf(n);
        for (auto & c : connections) uf.Union(c[0], c[1]);
        return uf.Count() - 1;
    }
};
// @lc code=end

