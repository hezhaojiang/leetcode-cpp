/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
#include<string>
using namespace std;
// @lc code=start

class Solution {
public:
    int strStr(string haystack, string needle) {
//#define FORCE /* 暴力法 */
#ifdef FORCE
        int haylength = haystack.length();
        int nedlength = needle.length();
        for(int i = 0; i <= haylength - nedlength; i++)
        {
            int j = 0;
            for(j = 0; j < nedlength; j++)
            {
                if(haystack[i+j] != needle[j]) break;
            }
            if(j == nedlength) return i;
        }
        return -1;
#endif
    }
};
// @lc code=end

