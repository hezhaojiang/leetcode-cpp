/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        /* 位运算的状态转移图：
         * 1. 异或
         *    <---1----
         *   ↓        |
         *   0  -1->  1
         * ↙ ↖    ↙ ↖
         * --0-→   --0-→
         * 可类比画出三种状态的状态转移图：
         * 00 --> 01 --> 10
         * ↑<------------↓
         * 其中每个状态需要两位来表示，
         * 故使用两个变量 ones 和 two 分别表示状态低位和状态高位
         * 对于每个位的状态变化如下：
         * - 如果接收的位状态为 0，则该位状态不变
         *      - one = one;
         *      - two = two;
         * - 如果接收的位状态位 1，则：
         *      - if(one == 0 && two == 0) one = 1; two = 0;
         *      - if(one == 1 && two == 0) one = 0; two = 1;
         *      - if(one == 0 && two == 1) one = 0; two = 0;
         *  > if (two == 1) ==> one = 0
         *  > if (two == 0) ==> one = one ^ num
         *                  ==> one = one ^ num & ~two
         *  > one 计算完成，后续使用新 one 值进行计算
         *  > if (one == 1) ==> two = 0
         *  > if (one == 0) ==> two = two ^ num
         *                  ==> two = two ^ num & ~one
         */
        for (auto num : nums) {
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }
};
// @lc code=end

