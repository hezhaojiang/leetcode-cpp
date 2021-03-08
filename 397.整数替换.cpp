/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n == INT_MAX) return 32;
        if (n & 1) {
            if (n & 2 && n != 3) return integerReplacement(n + 1 >> 1) + 2;
            else return integerReplacement(n - 1 >> 1) + 2;
        }
        else return integerReplacement(n >> 1) + 1;
    }
};
// @lc code=end

