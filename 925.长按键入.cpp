/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int N = name.length();
        int M = typed.length();
        int i = 0, j = 0;
        while (i < N || j < M) {
            if (name[i] == typed[j]) { i++; j++; continue; }
            if (j == 0 || typed[j - 1] != typed[j]) return false;
            while (j < M && typed[j - 1] == typed[j]) j++;
        }
        if (i == N && j == M) return true;
        return false;
    }
};
// @lc code=end

