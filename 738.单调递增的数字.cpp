/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string strN = to_string(N);
        int len = strN.length();
        int i = 0;
        for (i = 0; i < len - 1; i++) {
            if (strN[i] > strN[i + 1]) {
                while (i >= 0 && strN[i] > strN[i + 1]) strN[i--]--;
                break;
            }
        }
        for (i = i + 2; i < len; i++) strN[i] = '9';
        return atoi(strN.c_str());
    }
};
// @lc code=end

