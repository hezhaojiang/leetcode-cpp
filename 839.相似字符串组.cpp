/*
 * @lc app=leetcode.cn id=839 lang=cpp
 *
 * [839] 相似字符串组
 */
#include<vector>
#include<string>
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
            if (rank[rootA] == rank[rootB]) rank[rootB]++;
            count--;
        }
    }
};
class Solution {
private:
    bool check(const string& s1, const string& s2) {
        int dif = 0;
        for (int i = 0; i < s1.size(); i++) dif += (s1[i] != s2[i]);
        return (dif == 0 || dif == 2);
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        int N = strs.size();
        UnionFind uf(N);
        for (int i = 0; i < N; i++) for (int j = 0; j < i; j++) {
            if (uf.Find(i) == uf.Find(j)) continue;
            if (!check(strs[i], strs[j])) continue;
            uf.Union(i, j);
        }
        return uf.Count();
    }
};
// @lc code=end

