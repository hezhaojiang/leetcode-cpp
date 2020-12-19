/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) swap(s[i++], s[j--]);
        return;
    }
};
// @lc code=end

