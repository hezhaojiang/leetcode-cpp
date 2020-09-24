/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x, mid;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (1LL * mid * mid == x) return mid;
            else if (1LL * mid * mid > x) end = mid;
            else if (1LL * mid * mid < x) start = mid;
        }
        if (1LL * end * end <= x) return end;
        else return start;
    }
};
// @lc code=end

