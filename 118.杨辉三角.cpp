/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        if (!numRows) return result;
        result[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            result[i].push_back(1);
            for (int j = 0; j < result[i - 1].size() - 1; j++) {
                result[i].push_back(result[i - 1][j] + result[i - 1][j + 1]);
            }
            result[i].push_back(1);
        }
        return result;
    }
};
// @lc code=end
