/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */
#include<iostream>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseParentheses(string s) {
        string result;
        int inParentheses = 0;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') inParentheses++;
            else if (s[i] == ')') inParentheses--;
            if (inParentheses == 0 && isalpha(s[i])) result = result + s[i];
            else {
                if (inParentheses == 1 && s[i] == '(') start = i + 1;
                else if (inParentheses == 0 && s[i] == ')') {
                    end = i - 1;
                    string sub = reverseParentheses(s.substr(start, end - start + 1));
                    reverse(sub.begin(), sub.end());
                    result.append(sub);
                }
            }
        }
        return result;
    }
};
// @lc code=end
