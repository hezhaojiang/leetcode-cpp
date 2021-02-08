/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
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
    void markIand(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        for (auto &d : dis) {
            int x = i + d[0], y = j + d[1];
            if (isvalid(x, y) && grid[x][y] == '1') markIand(grid, x, y);
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        M = grid.size();
        N = grid[0].size();
        /* 寻找未发现的岛屿 */
        for (int i = 0; i < M; i++) for(int j = 0; j < N; j++) {
            if (grid[i][j] == '1') { /* 找到新岛屿 进行标记 */
                markIand(grid, i, j);
                num++;
            }
        }
        return num;
    }
};
// @lc code=end

int main() {
    Solution solve;
    vector<vector<char>> grid{{'1','1','1','1','0'}, {'1','1','0','1','0'}};
    solve.numIslands(grid);
    return 0;
}
