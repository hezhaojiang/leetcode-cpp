/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask = 1 << 30; // 最高位开始
        int ret = 0;
        while(mask > 0 && (m & mask) == (n & mask)) { //寻找相同前缀
            ret |= m & mask;
            mask >>= 1;
        }
        return ret;
    }
};
// @lc code=end

