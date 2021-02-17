/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int M = nums.size();
        int N = nums[0].size();
        if (N * M != r * c) return nums;
        vector<vector<int>> res(r, vector<int>(c, 0));
        int m = 0, n = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                res[i][j] = nums[m][n++];
                if (n == N) n = 0, m++;
            }
        return res;
    }
};
// @lc code=end
