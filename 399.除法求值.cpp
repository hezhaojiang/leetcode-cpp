/* 
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class UnionFind {
private:
    vector<int> f;
    vector<double> v;
public:
    UnionFind(int num) {
        f.resize(num);
        v.resize(num, 1.0);
        for (int i = 0; i < num; i++) f[i] = i;
    }
    void Union(int a, int b, double value) {
        int fa = Find(a);
        int fb = Find(b);
        f[fa] = fb;
        v[fa] = value * v[b] / v[a];
    }
    int Find(int a) {
        if (f[a] != a) {
            int father = Find(f[a]);
            v[a] = v[a] * v[f[a]];
            f[a] = father;
        }
        return f[a];
    }
    double Value(int a) { return v[a]; }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nvars = 0;
        unordered_map<string, int> variables;

        int n = equations.size();
        for (const auto & e : equations) {
            if (!variables.count(e[0])) variables[e[0]] = nvars++;
            if (!variables.count(e[1])) variables[e[1]] = nvars++;
        }
        UnionFind uf(nvars);
        for (int i = 0; i < n; i++) {
            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
            uf.Union(va, vb, values[i]);
        }
        vector<double> ret;
        for (const auto& q: queries) {
            double result = -1.0;
            if (variables.count(q[0]) && variables.count(q[1])
                && uf.Find(variables[q[0]]) == uf.Find(variables[q[1]]) )
                result = uf.Value(variables[q[0]]) / uf.Value(variables[q[1]]);
            ret.push_back(result);
        }
        return ret;
    }
};
// @lc code=end

/* Test Main */
int main(void)
{
    Solution solve;
    vector<vector<string>> equations = {{"a","b"},{"e","f"},{"b","e"}};
    vector<double> values = {3.4,1.4,2.3};
    vector<vector<string>> queries{{"a","f"}};
    solve.calcEquation(equations, values, queries);
    return 0;
}
