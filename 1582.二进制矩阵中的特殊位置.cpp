/*
 * @lc app=leetcode.cn id=1582 lang=cpp
 *
 * [1582] 二进制矩阵中的特殊位置
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = 0;
        vector<int> rows(m, 0), cols(n, 0);
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            rows[i] += mat[i][j];
            cols[j] += mat[i][j];
        }
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            if (rows[i] == 1 && cols[j] == 1 && mat[i][j] == 1) res++;
        }
        return res;
    }
};
// @lc code=end
