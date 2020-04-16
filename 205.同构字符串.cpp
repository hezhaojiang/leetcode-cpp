/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
#include<map>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        char index[128] = { 0 };
        map<char, char> mapCc;
        for(int i = 0; i < s.length(); i++)
        {
            if(mapCc.find(s[i]) == mapCc.end()) 
            {
                if(index[t[i]]) return false;
                mapCc[s[i]] = t[i];
                index[t[i]] = 1;
            }
            else
                if(mapCc[s[i]] != t[i]) return false;
        }
        return true;
    }
};
// @lc code=end

