/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        auto ans = vector<int>(len1 + len2, 0);
        string res = "";
        for (int i = len2 - 1; i >= 0; i--) {
            for (int j = 0; j < len1; j++) {
                int pos = (len2 - 1 - i) + (len1 - 1 - j);
                ans[pos] += (num1[j] - '0') * (num2[i] - '0');
                int ins = pos;
                while (ans[ins] >= 10) {
                    ans[ins + 1] += ans[ins] / 10;
                    ans[ins++] %= 10;
                }
            }
        }
        int pos = len1 + len2;
        while(pos > 0 && ans[--pos] == 0);
        for (; pos >= 0; pos--) {
            res += to_string(ans[pos]);
        }
        return res;
    }
};
// @lc code=end

