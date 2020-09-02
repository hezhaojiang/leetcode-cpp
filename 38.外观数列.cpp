/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string pre = "1";
        for (int i = 2; i <= n; i++) {
            char cnum;
            int count = 0; 
            string last = "";
            for (int j = 0; j < pre.length(); j++) {
                if (count == 0 || cnum == pre[j]) { count++; cnum = pre[j]; }
                if (count != 0 && cnum != pre[j]) {
                    last.append(to_string(count) + cnum);
                    count = 1;
                    cnum = pre[j];
                }
                if (j == pre.length() - 1) last.append(to_string(count) + cnum);
            }
            pre = last;
        }
        return pre;
    }
};
// @lc code=end

