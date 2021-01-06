/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */
#include<string>
#include<vector>
#include<unordered_map>
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        UnionFind uf(N);
        for (int i = 0; i < N; i++) for (int j = 0; j < i; j++) {
            if (isConnected[i][j] == 1) uf.Union(i, j);
        }
        return uf.Count();
    }
};
// @lc code=end

/* Test Main */
int main(void)
{
    Solution solve;
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    solve.findCircleNum(isConnected);
    return 0;
}
