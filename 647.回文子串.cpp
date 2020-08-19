/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
private: 
    int result = 0;
public:
    int countSubstrings(string s) {
        // 预处理
        string s1;
        for (int i = 0; i < s.length(); i++) {
            s1 += "#";
            s1 += s[i];
        }
        s1 += "#";

        for (int i = 0; i < s1.length(); i++) {
            int j = s1[i] == '#' ? 1 : 2;
            for (; i - j >= 0 && i + j < s1.length(); j = j + 2) {
                if (s1[i - j] == s1[i + j]) result++;
                else break;
            }
        }
        return result + s.length();
    }
};
// @lc code=end

