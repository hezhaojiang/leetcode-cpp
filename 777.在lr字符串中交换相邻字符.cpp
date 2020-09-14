/*
 * @lc app=leetcode.cn id=777 lang=cpp
 *
 * [777] 在LR字符串中交换相邻字符
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.length() != end.length()) return false;
        /* L 只能左移， R 只能右移 */
        int RCount = 0, LCount = 0, XCount = 0;
        string S, T;
        for (int i = 0; i < start.length(); i++) {
            if (start[i] == 'R')  RCount++;
            else if (start[i] == 'L') LCount--;
            if (end[i] == 'R')  RCount--;
            else if (end[i] == 'L') LCount++;
            if (start[i] != 'X') S += start[i];
            if (end[i] != 'X') T += end[i];
            if (RCount < 0 || LCount < 0) return false;
        }
        if (RCount != 0 || LCount != 0 || S != T) return false;
        return true;
    }
};
// @lc code=end

