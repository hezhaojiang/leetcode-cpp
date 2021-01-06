/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class UnionFind {
private:
    vector<int> f;
public:
    UnionFind(int num) {
        f.resize(num);
        for (int i = 0; i < num; i++) f[i] = i;
    }
    void Union(int a, int b) {
        int fa = Find(a);
        int fb = Find(b);
        f[fa] = fb;
    }
    int Find(int a) {
        if (f[a] != a) {
            int father = Find(f[a]);
            f[a] = father;
        }
        return f[a];
    }
    bool oneUnion(int a, int b) {
        int fa = Find(a);
        int fb = Find(b);
        return fa == fb;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int nvars = 0;
        unordered_map<char, int> variables;

        int n = equations.size();
        for (const auto & e : equations) {
            if (!variables.count(e[0])) variables[e[0]] = nvars++;
            if (!variables.count(e[3])) variables[e[3]] = nvars++;
        }
        UnionFind uf(nvars);
        for (int i = 0; i < n; i++) {
            if (equations[i][1] == '=') {
                int va = variables[equations[i][0]], vb = variables[equations[i][3]];
                uf.Union(va, vb);
            }
        }
        for (int i = 0; i < n; i++) {
            if (equations[i][1] == '!') {
                int va = variables[equations[i][0]], vb = variables[equations[i][3]];
                if (uf.oneUnion(va, vb)) return false;
            }
        }
        return true;
    }
};
// @lc code=end

