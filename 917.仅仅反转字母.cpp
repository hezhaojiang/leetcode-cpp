/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */
#include<iostream>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0;
        int j = S.length() - 1;
        while (i < j) {
            if (!isalpha(S[i])) i++;
            else if (!isalpha(S[j])) j--;
            else swap(S[i++], S[j--]);
        }
        return S;
    }
};
// @lc code=end

