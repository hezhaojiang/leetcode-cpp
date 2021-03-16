/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<long> result;
        result.resize(obstacleGrid[0].size());
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] != 0) result[j] = 0;
                else {
                    if (i == 0 && j == 0) result[j] = 1;
                    else if (i != 0 && j == 0) result[j] = result[j];
                    else if (i == 0 && j != 0) result[j] = result[j - 1];
                    else result[j] = result[j] + result[j - 1];
                }
            }
        }
        return result.back();
    }
};
// @lc code=end
