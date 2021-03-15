/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int up = 0, down = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        vector<int> res;
        while (up <= down && left <= right) {
            for (int i = left; i <= right; i++) res.push_back(matrix[up][i]);
            for (int i = up + 1; i <= down; i++) res.push_back(matrix[i][right]);
            for (int i = right - 1; i >= left && up != down; i--) res.push_back(matrix[down][i]);
            for (int i = down - 1; i > up && left != right; i--) res.push_back(matrix[i][left]);
            up++, down--, left++, right--;
        }
        return res;
    }
};
// @lc code=end
