/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Bellman-Ford 算法
        vector<int> dis(n, INT_MAX / 2);
        dis[src] = 0;
        for (int count = 0; count <= K; count++) {
            vector<int> disnext(dis);
            for (auto& f : flights) disnext[f[1]] = min(disnext[f[1]], dis[f[0]] + f[2]);
            dis = disnext;
        }
        return (dis[dst] == INT_MAX / 2) ? -1 : dis[dst];
    }
};
// @lc code=end
