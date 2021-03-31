/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = 0, down = matrix.size() - 1;
        while (up <= down) {
            int mid = up + down >> 1;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) down = mid - 1;
            else up = mid + 1;
        }
        if (down < 0) return false;
        int l = 0, r = matrix[0].size() - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (matrix[down][mid] == target) return true;
            else if (matrix[down][mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};
// @lc code=end

