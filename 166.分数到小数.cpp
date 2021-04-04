/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string sint, sdot, res;
        long long lnumerator = numerator, ldenominator = denominator;
        if (lnumerator == 0) return "0";
        if (lnumerator < 0 && ldenominator < 0) {
            lnumerator *= -1;
            ldenominator *= -1;
        }
        else if (lnumerator < 0) {
            lnumerator *= -1;
            sint = "-";
        }
        else if (ldenominator < 0) {
            ldenominator *= -1;
            sint = "-";
        }
        sint += to_string(lnumerator / ldenominator);
        int rest = lnumerator % ldenominator;
        if (rest == 0) return sint;
        unordered_map<int, int> rest_pos;
        while (rest) {
            rest *= 10;
            if (rest_pos.count(rest)) {
                res += sint + ".";
                res += sdot.substr(0, rest_pos[rest]) + "(";
                res += sdot.substr(rest_pos[rest]) + ")";
                return res;
            }
            else rest_pos[rest] = sdot.length();
            sdot += rest / ldenominator + '0';
            rest %= ldenominator;
        }
        return sint + "." + sdot;
    }
};
// @lc code=end

