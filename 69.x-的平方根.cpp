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
        int l = 0, r = x;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (1LL * mid * mid == x) return mid;
            else if (1LL * mid * mid > x) r = mid - 1;
            else if (1LL * mid * mid < x) l = mid + 1;
        }
        return r;
    }
};
// @lc code=end

