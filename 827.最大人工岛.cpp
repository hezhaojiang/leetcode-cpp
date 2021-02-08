/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int M, N;
    const vector<vector<int>> dis{{1,0},{-1,0},{0,1},{0,-1}};
    bool isvalid(int i, int j) {
        return i >= 0 && j >= 0 && i < M && j < N;
    }
    int markIand(vector<vector<int>>& grid, int i, int j, int no) {
        int res = 1;
        grid[i][j] = no;
        for (auto &d : dis) {
            int x = i + d[0], y = j + d[1];
            if (isvalid(x, y) && grid[x][y] == 1) res += markIand(grid, x, y, no);
        }
        return res;
    }
    int largestIsland(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        int noIand = 2;
        int maxArea = 0;
        vector<int> Iand(2, 0);
        /* 寻找未发现的岛屿 */
        for (int i = 0; i < M; i++) for(int j = 0; j < N; j++) {
            if (grid[i][j] == 1) { /* 找到新岛屿 进行标记 */
                int area = markIand(grid, i, j, noIand);
                Iand.push_back(area);
                maxArea = max(maxArea, area);
                noIand++;
            }
        }
        
        for (int i = 0; i < M; i++) for(int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                int area = 1;
                unordered_map<int, int> mp;
                for (auto &d : dis) {
                    int x = i + d[0], y = j + d[1];
                    if (isvalid(x, y) && !mp.count(grid[x][y])) {
                        mp[grid[x][y]] = 1;
                        area += Iand[grid[x][y]];
                    }
                }
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
// @lc code=end

int main() {
    Solution solve;
    vector<vector<int>> grid{{1,1}, {1,0}};
    solve.largestIsland(grid);
    return 0;
}
