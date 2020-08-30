/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include<iostream>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int start = 0;
        int end = 0;
        bool revers = true;
        for (int i = 0; i < s.length(); i++) {
            if ((i + 1) % k == 0 || i == s.length() - 1) {
                end = i;
                if (revers)
                    while (start < end) swap(s[start++], s[end--]);
                start = i + 1;
                revers = !revers;
            }
        }
        return s;
    }
};
// @lc code=end

