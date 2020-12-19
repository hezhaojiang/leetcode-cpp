/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
private:
    bool isaeiou(char c) {
        string str = "aeiouAEIOU";
        for (auto index : str)
            if (index == c) return true;
        return false;
    }
public:
    string reverseVowels(string s) {
        for(int i = 0, j = s.length() - 1; i < j; i++, j--) {
            while (i < j && !isaeiou(s[i])) i++;
            while (i < j && !isaeiou(s[j])) j--;
            swap(s[i], s[j]);
        }
        return s;
    }
};
// @lc code=end

