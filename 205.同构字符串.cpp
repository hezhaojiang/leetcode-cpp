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
        //if(s.length() != t.length()) return false;
        char indexs[128] = { 0 };
        char indext[128] = { 0 };
        map<char, char> mapCc;
        for (int i = 0; i < s.length(); i++) {
            if (indexs[s[i]] == 0) {
                if (indext[t[i]]) return false;
                indexs[s[i]] = t[i];
                indext[t[i]] = 1;
            }
            else if (indexs[s[i]] != t[i]) return false;
        }
        return true;
    }
};
// @lc code=end

