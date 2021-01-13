/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */
#include<vector>
#include<string>
#include<algorithm>
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
    int Find(int a) { return a == f[a] ? a : f[a] = Find(f[a]); }
    void Union(int a, int b) {
        int fa = Find(a);
        int fb = Find(b);
        if (fa != fb) f[fa] = fb;
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int N = s.length();
        UnionFind uf(N);
        for (auto & pair : pairs) uf.Union(pair[0], pair[1]);
        unordered_map<int, vector<int>> ms;
        for (int i = 0; i < N; i++)  ms[uf.Find(i)].push_back(s[i]);
        for (auto & m : ms) sort(m.second.begin(), m.second.end(), greater<int>());
        for (int i = 0; i < N; i++) {
            int c = uf.Find(i);
            s[i] = ms[c].back();
            ms[c].pop_back();
        }
        return s;
    }
};
// @lc code=end

/* Test Main */
int main(void)
{
    Solution solve;
    string s = "dcab";
    vector<vector<int>> pairs = {{0,3},{1,2}};
    solve.smallestStringWithSwaps(s, pairs);
    return 0;
}

