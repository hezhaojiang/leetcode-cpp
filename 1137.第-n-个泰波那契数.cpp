/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        int first = 0, second = 1, third = 1;
        if (n == 0 || n == 1) return n;
        if (n == 2) return 1;
        int res;
        for (int i = 2; i < n; i++) {
            res = first + second + third;
            first = second, second = third, third = res;
        }
        return res;
    }
};
// @lc code=end
