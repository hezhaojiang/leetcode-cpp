/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        /************************ 暴力算法 超时 ************************
        string r = s;
        reverse(r.begin(), r.end());
        for (int offset = 0; offset < s.size(); offset++) {
            int i = 0;
            for (i = 0; i < s.size() - offset; i++) {
                if (s[i] != r[offset + i]) break;
            }
            if (i == s.size() - offset) return r.substr(0, offset) + s;
        }
        return r + s;
        ************************ 暴力算法 超时 ************************/
        string r = s;
        reverse(r.begin(), r.end());
        string rs = s + "#" + r; /* abab -> abab#baba */
        /* 利用 KMP 算法求最长公共前后缀 */
        int i = 0;
        int j = -1;
        vector<int> next;
        next.resize(rs.length());
        next[0] = -1;
        while (i < rs.length() - 1) {
            if(j == -1 || rs[i] == rs[j]) next[++i] = ++j;
            else j = next[j];
        }
        return r.substr(0, r.length() - next[rs.length() - 1] - 1) + s;
    }
};
// @lc code=end

