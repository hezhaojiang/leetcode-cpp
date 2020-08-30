/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */
#include<iostream>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' || i == s.length() - 1) {
                if(i != s.length() - 1) end = i - 1;
                else end = i;
                while (start < end) swap(s[start++], s[end--]);
                start = i + 1;
                end = i + 1;
            }
        }
        return s;
    }
};
// @lc code=end

