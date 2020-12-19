/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
#include<string>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        /* 去除多余空格 */
        int i = 0, j = 0;
        bool lastispace = true;
        while (j < s.size()) {
            if (lastispace && s[j] == ' ') { j++; continue; }
            if (i != j) s[i] = s[j];
            lastispace = (s[i] == ' ');
            i++; j++;
        }
        if (s[i - 1] == ' ') i--;
        s = s.substr(0, i);
        /* 翻转所有字符 */
        reverse(s.begin(), s.end());
        /* 翻转所有单词 */
        int start = 0, end = 0;
        for (i = 0, start = 0; i < s.size(); i++) {
            if (s[i] == ' ') end = i - 1;
            else if (i == s.size() - 1) end = i;
            else continue;
            do swap(s[start++], s[end--]); while (start < end);
            start = i + 1;
        }
        return s;
    }
};
// @lc code=end
int main(void)
{
    Solution solve;
    string s = solve.reverseWords(" practice   makes   perfect");
    cout << s << endl;
    return 0;
}


