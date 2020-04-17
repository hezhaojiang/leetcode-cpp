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
    void markIand(vector<vector<char>>& grid, int i, int j)
    {
        grid[i][j] = '0';

        if(i - 1 >= 0 && grid[i - 1][j] == '1') markIand(grid, i - 1, j);
        if(i + 1 < grid.size() && grid[i + 1][j] == '1') markIand(grid, i + 1, j);
        if(j - 1 >= 0 && grid[i][j - 1] == '1') markIand(grid, i, j - 1);
        if(j + 1 < grid[0].size() && grid[i][j + 1] == '1') markIand(grid, i, j + 1);

#if 0
        int x[4] = {0, 0, -1, 1};
        int y[4] = {1, -1, 0, 0};
        for(int index = 0; index < 4; index++)
        {
            if(i + x[index] >= 0 || i + x[index] < grid.size()
                || j + y[index] >= 0 || j + y[index] < grid[0].size())
                if(grid[i + x[index]][j + y[index]] == '1')
                    markIand(grid, i + x[index], j + y[index]);
        }
#endif
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        /* 寻找未发现的岛屿 */
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1') /* 找到新岛屿 进行标记 */
                {
                    markIand(grid, i, j);
                    num++;
                }
            }
        }
        return num;
    }
};
// @lc code=end

