/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 1) return "";

        // 预处理
        string s1;
        for (int i = 0; i < len; i++) {
            s1 += "#";
            s1 += s[i];
        }
        s1 += "#";

        len = s1.length();
        int MaxRight = 0;     // 当前访问到的所有回文子串，所能触及的最右一个字符的位置
        int Mid = 0;          // MaxRight 对应的回文串的对称轴所在的位置
        int MaxRL = 0;        // 最大回文串的回文半径
        int MaxMid = 0;       // MaxRL 对应的回文串的对称轴所在的位置
        vector<int> RL(len);  // RL[i] 表示以第 i 个字符为对称轴的回文串的回文半径

        for (int i = 0; i < len; i++) {
            if (i < MaxRight) RL[i] = min(RL[2 * Mid - i], MaxRight - i);
            else RL[i] = 1;

            // 尝试扩展 RL[i]，注意处理边界
            while (i - RL[i] >= 0      // 可以把 RL[i] 理解为左半径, 即回文串的起始位不能小于 0
                   && i + RL[i] < len  // 同上, 即回文串的结束位不能大于总长
                   && s1[i - RL[i]] == s1[i + RL[i]]) {  // 回文串特性，左右扩展，判断字符串是否相同
                RL[i] += 1;
            }

            // 更新 MaxRight, Mid
            if (RL[i] + i - 1 > MaxRight) {
                MaxRight = RL[i] + i - 1;
                Mid = i;
            }

            // 更新 MaxRL, MaxPos
            if (MaxRL <= RL[i]) {
                MaxRL = RL[i];
                MaxMid = i;
            }
        }
        return s.substr((MaxMid - MaxRL + 1) / 2, MaxRL - 1);
    }
};
// @lc code=end
