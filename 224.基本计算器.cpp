/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    int index = 0;

public:
    int calculate(string s) {
        int n = s.length();
        char operate = '+';
        int num = 0;
        vector<int> stk;
        while (index < n) {
            char ch = s[index++];
            if (ch >= '0') num = num * 10 - '0' +  ch;
            if (ch == '(') num = calculate(s);
            if (ch < '0' || index == n) {
                if (index != n && ch == ' ') continue;
                if (operate == '+') stk.push_back(num);
                else if (operate == '-') stk.push_back(-num);
                //else if (operate == '*') stk.back() *= num;
                //else if (operate == '/') stk.back() /= num;
                operate = ch;
                num = 0;
            }
            if (ch == ')') break;
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
// @lc code=end
