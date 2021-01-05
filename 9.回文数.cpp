/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
#if 0
        string s = to_string(x);
        string t = s;
        reverse(s.begin(), s.end());
        return s == t;
#endif
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
// @lc code=end

