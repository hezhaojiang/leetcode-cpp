/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start

class Solution {
private:
    int BASE = 10000;
    int DIFF = 1;
public:
    int strStr(string haystack, string needle) {
//#define FORCE /* 暴力法 */
//#define KMP /* KMP法 */
#define Rabin_Karp /* Rabin_Karp */
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
#ifdef KMP
        int haylength = haystack.length();
        int nedlength = needle.length();
        if(0 == nedlength) return 0;
        if(0 == haylength) return -1;

        vector<int> next;
        next.resize(nedlength);
        next[0] = -1;

        int i = 0;
        int j = -1;
        while(i < nedlength - 1)
        {
            if(j == -1 || needle[i] == needle[j]) next[++i] = ++j;
            else j = next[j];
        }

        i = 0;
        j = 0;
        while((i < haylength) && (j < nedlength))
        {
            if(j == -1 || haystack[i] == needle[j]) { i++; j++; }
            else j = next[j];
        }
        if(j == nedlength) return i - j;
        else return -1;
#endif
#ifdef Rabin_Karp
        int haylength = haystack.length();
        int nedlength = needle.length();
        if(0 == nedlength) return 0;
        if(0 == haylength) return -1;

        /* a * 31 ^ m */
        int nedhash = 0;
        for(auto a : needle)
        {
            nedhash = (nedhash * 31 + a) % BASE;
            DIFF = (DIFF * 31) % BASE;
        }
        
        int hayhash = 0;
        for(int i = 0; i < nedlength; i++)
            hayhash = (hayhash * 31 + haystack[i]) % BASE;

        for(int i = 0; i <= haylength - nedlength; i++)
        {
            if(0 != i)
            {
                hayhash = (hayhash * 31 + haystack[i + nedlength - 1]) % BASE;
                hayhash = hayhash - (DIFF * haystack[i - 1])  % BASE;
                if(hayhash < 0) hayhash += BASE;
            }
            if(hayhash == nedhash) 
            {
                int j = 0;
                for(j = 0; j < nedlength; j++)
                    if(haystack[i + j] != needle[j]) break;
                if(j == nedlength) return i;
            }
        }
        return -1;
#endif
    }
};
// @lc code=end

