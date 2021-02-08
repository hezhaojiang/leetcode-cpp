/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
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
    int markIand(vector<vector<int>>& grid, int i, int j) {
        if (!isvalid(i, j) || grid[i][j] == 0) return 1;
        if (grid[i][j] == 2) return 0;
        int res = 0;
        grid[i][j] = 2;
        for (auto &d : dis) {
            int x = i + d[0], y = j + d[1];
            res += markIand(grid, x, y);
        }
        return res;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        int maxPerimeter = 0;
        /* 寻找未发现的岛屿 */
        for (int i = 0; i < M; i++) for(int j = 0; j < N; j++) {
            if (grid[i][j] == 1) { /* 找到新岛屿 进行标记 */
                int Perimeter = markIand(grid, i, j);
                maxPerimeter = max(maxPerimeter, Perimeter);
            }
        }
        return maxPerimeter;
    }
};
// @lc code=end

