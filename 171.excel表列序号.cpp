/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int N = s.size();
        for (int i = 0; i < N; i++) {
            res = res * 26 + (s[i] - 'A' + 1);
        }
        return res;
    }
};
// @lc code=end

