/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = ((dividend ^ divisor) & (0x1 << 31)) >> 31;
        long divd = dividend;
        long divs = divisor;
        divd = divd & (0x1 << 31) ? (divd - 1) ^ -1 : divd;
        divs = divs & (0x1 << 31) ? (divs - 1) ^ -1 : divs;
        int ob = 0;
        long result = 0;
        while(divs < divd >> 1) 
        {
            divs <<= 1;
            ob++;
        }
        while(divd >= divs)
        {
            divd -= divs;
            result += 1 << ob;
            while(ob && divd < divs)
            {
                divs >>= 1;
                ob--;
            }
        }
        result = sign ? (result ^ -1) + 1 : result;
        if(result > INT_MAX) result = INT_MAX;
        else if(result < INT_MIN) result = INT_MIN;
        return result;
    }
};
// @lc code=end

