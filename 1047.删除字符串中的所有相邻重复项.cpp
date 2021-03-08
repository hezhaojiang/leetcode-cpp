/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include <deque>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        string stk;
        for (auto c : s) {
            if (!stk.empty() && stk.back() == c) stk.pop_back();
            else stk.push_back(c);
        }
        return stk;
    }
};
// @lc code=end
