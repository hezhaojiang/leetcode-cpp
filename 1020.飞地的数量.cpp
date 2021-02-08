/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
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
    int Count() { return count; }
    void Union(int a, int b) {
        int rootA = Find(a), rootB = Find(b);
        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) swap(rootA, rootB);
            parent[rootA] = rootB;
            rank[rootB] += rank[rootA] + 1;
            count--;
        }
    }
    int Rank(int a) { return rank[Find(a)]; }
};
class Solution {
public:

    int numEnclaves(vector<vector<int>>& A) {
        int M = A.size();
        int N = A[0].size();
        int landCount = 0;
        UnionFind uf(N * M + 1);
#       define INDEX(i,j) ((i) * N + (j))
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) {
            if (A[i][j] != 1) continue;
            landCount++;
            if (i == 0 || i == M - 1 || j == 0 || j == N - 1) uf.Union(M * N, INDEX(i,j)); // 边界
            if (i != 0 && A[i - 1][j] == 1) uf.Union(INDEX(i - 1,j), INDEX(i,j)); // 上侧
            if (j != 0 && A[i][j - 1] == 1) uf.Union(INDEX(i,j - 1), INDEX(i,j)); // 左侧
        }
        return landCount - uf.Rank(N * M);
    }
};
// @lc code=end

