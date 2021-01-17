/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 */
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int deltaX = coordinates[0][0], deltaY = coordinates[0][1];
        int n = coordinates.size();
        for (int i = 0; i < n; ++i) {
            coordinates[i][0] -= deltaX;
            coordinates[i][1] -= deltaY;
        }
        int A = coordinates[1][1], B = -coordinates[1][0];
        for (int i = 2; i < n; ++i) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if (A * x + B * y != 0) return false;
        }
        return true;
    }
};
// @lc code=end

