/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    int M, N;
    const vector<vector<int>> dis{{1,0},{-1,0},{0,1},{0,-1}};
    bool isvalid(int i, int j) {
        return i >= 0 && j >= 0 && i < M && j < N;
    }
    bool isedge(int i, int j) {
        return i == 0 || j == 0 || i == M - 1 || j == N - 1;
    }
    bool markIand(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 1;
        bool isclose = true;
        if (isedge(i, j)) isclose = false;
        for (auto &d : dis) {
            int x = i + d[0], y = j + d[1];
            if (isvalid(x, y) && grid[x][y] == 0) {
                if (!markIand(grid, x, y)) isclose = false;
            }
        }
        return isclose;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int num = 0;
        M = grid.size();
        N = grid[0].size();
        /* 寻找未发现的岛屿 */
        for (int i = 0; i < M; i++) for(int j = 0; j < N; j++) {
            if (grid[i][j] == 0) { /* 找到新岛屿 进行标记 */
                if (markIand(grid, i, j)) num++;
            }
        }
        return num;
    }
};
// @lc code=end

