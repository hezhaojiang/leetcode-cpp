/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
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
        int res = 1;
        grid[i][j] = 0;
        for (auto &d : dis) {
            int x = i + d[0], y = j + d[1];
            if (isvalid(x, y) && grid[x][y] == 1) res += markIand(grid, x, y);
        }
        return res;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        int maxArea = 0;
        /* 寻找未发现的岛屿 */
        for (int i = 0; i < M; i++) for(int j = 0; j < N; j++) {
            if (grid[i][j] == 1) { /* 找到新岛屿 进行标记 */
                int area = markIand(grid, i, j);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
// @lc code=end

