/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> result;
        result.resize(n);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 || j == 0) result[j] = 1;
                else result[j] = result[j] + result[j - 1];
            }
        }
        return result.back();
    }
};
// @lc code=end

