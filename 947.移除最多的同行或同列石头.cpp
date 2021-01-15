/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
 */
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class UnionFind {
private:
    unordered_map<int,int> f;
    int count;
public:
    UnionFind() : count(0) { }
    int Count() { return count; }
    int Find(int a) {
        if (f.count(a)) return a == f[a] ? a : f[a] = Find(f[a]);
        else { f.insert(pair<int, int>{a, a}); count++; return a; }
    }
    void Union(int a, int b) {
        int fa = Find(a);
        int fb = Find(b);
        if (fa != fb) { f[fa] = fb; count--; }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf;
        for (auto & stone : stones) {
            // uf.Union(~stone[0], stone[1]);
            // uf.Union(stone[0] - 10001, stone[1]);
            uf.Union(stone[0] + 10001, stone[1]);
        }
        return stones.size() - uf.Count();
    }
};
// @lc code=end

