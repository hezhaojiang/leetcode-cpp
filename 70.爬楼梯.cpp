/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        vector<int> method;
        method.emplace_back(1);
        method.emplace_back(1);
        for(int i = 2; i <= n; i++)
        {
            method.emplace_back(method[i - 2] + method[i - 1]);
        }
        return method[n];
    } 
};
// @lc code=end

