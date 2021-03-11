/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        char operate = '+';
        int num = 0;
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0') num = num * 10 - '0' + s[i];
            if (s[i] < '0' || i == n - 1) {
                if (i != n - 1 && s[i] == ' ') continue;
                if (operate == '+') stk.push_back(num);
                else if (operate == '-') stk.push_back(-num);
                else if (operate == '*') stk.back() *= num;
                else if (operate == '/') stk.back() /= num;
                operate = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
// @lc code=end
