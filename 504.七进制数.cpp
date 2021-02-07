/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string res;
        int n = num;
        if (num < 0) n = -num;
        while (n != 0) {
            res += to_string(n % 7);
            n /= 7;
        }
        if (num < 0) res += '-';
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

