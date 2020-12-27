/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */
#include<string>
#include<stack>
using namespace std;
// @lc code=start
#define STATE_BEGIN 0
#define STATE_NUMBER 1
#define STATE_SYMBOL 2

class Solution {
public:
    int calculate(string s) {
        stack<int> sign;
        sign.push(1);
        int ans = 0, num = 0, op = 1;
        for (char c : s) {
            if (c == ' ') continue;
            if ('0' <= c && c <= '9') {
                num = num * 10 + (c - '0');
                continue;
            }
            ans += op * num;
            num = 0;
            if (c == '+') op = sign.top();
            else if (c == '-') op = -sign.top();
            else if (c == '(') sign.push(op);
            else if (c == ')') sign.pop();
        }
        ans += op * num;
        return ans;
    }
};
// @lc code=end

