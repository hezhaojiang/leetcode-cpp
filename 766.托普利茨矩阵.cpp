/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lst = 0;
        for (int i = 1; i < m; i++) {
            lst = i - 1;
            for (int j = 1; j < n; j++) {
                if (matrix[lst][j - 1] != matrix[i][j]) return false;
            }
        }
        return true;
    }
};
// @lc code=end
