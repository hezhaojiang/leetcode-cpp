/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 */
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
    int gcd(int a , int b) {
        return b ? gcd(b, a % b) : a;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = (int)str1.length(), len2 = (int)str2.length();
        if (str1 + str2 != str2 + str1) return "";
        string X = str1.substr(0, __gcd(len1, len2));
        // string X = str1.substr(0, gcd(len1, len2));
        return X;
    }
};
// @lc code=end

