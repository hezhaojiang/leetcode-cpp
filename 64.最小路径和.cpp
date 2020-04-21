/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> step;
        step.resize(grid[0].size());
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(i == 0 && j == 0) step[j] = grid[i][j];
                else if(i == 0 && j != 0) step[j] = step[j - 1] + grid[i][j];
                else if(i != 0 && j == 0) step[j] = step[j] + grid[i][j];
                else step[j] = min(step[j], step[j - 1]) + grid[i][j];
            }
        }
        return step.back();
    }
};
// @lc code=end

