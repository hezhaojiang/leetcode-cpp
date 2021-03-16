/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 *
 * [1289] 下降路径最小和  II
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        for (int i = 1; i < n; i++) {
            int minnum = INT_MAX, minpos = -1, seminnum = INT_MAX;
            for (int j = 0; j < m; j++) {
                if (arr[i - 1][j] <= minnum) seminnum = minnum, minnum = arr[i - 1][j], minpos = j;
                else if (arr[i - 1][j] < seminnum) seminnum = arr[i - 1][j];
            }
            for (int j = 0; j < m; j++) {
                int minvalue = (j == minpos) ? seminnum : minnum;
                arr[i][j] += minvalue;
            }
        }
        return *min_element(arr[n - 1].begin(), arr[n - 1].end());
    }
};
// @lc code=end

int main() {
    Solution solve;
    vector<vector<int>> arr{{-73, 61, 43, -48, -36},
                            {3, 30, 27, 57, 10},
                            {96, -76, 84, 59, -15},
                            {5, -49, 76, 31, -7},
                            {97, 91, 61, -46, 67}};
    solve.minFallingPathSum(arr);
    return 0;
}
