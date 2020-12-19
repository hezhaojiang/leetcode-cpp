/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /* 对角线翻转 */
        for (int i = 0; i < matrix.size(); i++) for (int j = 0; j < i; j++)
            swap(matrix[i][j], matrix[j][i]);
        /* 左右翻转 */
        for (auto &m : matrix) reverse(m.begin(), m.end());
        return;
    }
};
// @lc code=end

