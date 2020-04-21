/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<int> step;
        step.resize(dungeon[0].size());
        int rowMax = dungeon.size() - 1;
        int colMax = dungeon[0].size() - 1;
        for(int i = rowMax; i >= 0; i--)
        {
            for(int j = colMax; j >= 0; j--)
            {
                if(i == rowMax && j == colMax) 
                    step[j] = 1 - dungeon[i][j];
                else if(i == rowMax && j != colMax) 
                    step[j] = step[j + 1] - dungeon[i][j];
                else if(i != rowMax && j == colMax) 
                    step[j] = step[j] - dungeon[i][j];
                else 
                    step[j] = min(step[j], step[j + 1]) - dungeon[i][j];
                if(step[j] <= 0) step[j] = 1;
            }
        }
        return step.front();
    }
};
// @lc code=end

