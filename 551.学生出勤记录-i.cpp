/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A' && ++absent == 2) return false;
            else if (s[i] == 'L') { 
                if (i > 1 && s[i - 1] == 'L' && s[i - 2] == 'L') return false;
            }
        }
        return true;
    }
};
// @lc code=end
