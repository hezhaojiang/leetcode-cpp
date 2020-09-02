/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */
#include <string>
using namespace std;
// @lc code=start
class Solution{
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string result = "";
        string hex[16] = { "0", "1", "2", "3", "4", "5", "6", "7",
                           "8", "9", "a", "b", "c", "d", "e", "f" };
        //return hex[(num >> ((7 - 5) * 4)) & 0xf];
        for (int i = 0; i < 8; i++) {
            string t = hex[(num >> ((7 - i) * 4)) & 0xf];
            if (result != "" || t != "0") result.append(t);
        }
        return result;
    }
};
// @lc code=end
