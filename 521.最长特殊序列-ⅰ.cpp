/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 */
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.length() != b.length()) return max(a.length(), b.length());
        else {
            if (a == b) return -1;
            else return a.length();
        }
    }
};
// @lc code=end

