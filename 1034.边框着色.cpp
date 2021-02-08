/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边框着色
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    int M = 0;
    int N = 0;
    vector<vector<int>> distance{{1,0},{-1,0},{0,1},{0,-1}};
    bool isvalid(int r, int c) {
        return r >= 0 && r < M && c >= 0 && c < N;
    }
    void dfs(vector<vector<int>>& grid, int r0, int c0, int color, vector<vector<int>>& visited) {
        if (visited[r0][c0]) return;
        visited[r0][c0] = 1;
        bool is_edge = false;
        for (auto & d : distance) {
            int r = r0 + d[0];
            int c = c0 + d[1];
            if (!isvalid(r, c) || (!visited[r][c] && grid[r][c] != grid[r0][c0])) is_edge = true;
            if ( isvalid(r, c) && grid[r][c] == grid[r0][c0]) dfs(grid, r, c, color, visited);
        }
        if (is_edge) grid[r0][c0] = color;
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        if (grid[r0][c0] == color) return grid;
        M = grid.size();
        N = grid[0].size();
        vector<vector<int>> visited(M, vector<int>(N, 0));
        dfs(grid, r0, c0, color, visited);
        return grid;
    }
};
// @lc code=end

int main() {
    Solution solve;
    vector<vector<int>> grid{{1,1},{1,2}};
    solve.colorBorder(grid, 0, 0, 3);
    return 0;
}

