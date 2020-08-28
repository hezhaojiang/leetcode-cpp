/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        int Uptime = 0;
        int Rightime = 0;
        for (auto & c : moves) {
            if (c == 'R') Rightime++;
            else if (c == 'L') Rightime--;
            else if (c == 'U') Uptime++;
            else if (c == 'D') Uptime--;
        }
        if (Rightime == 0 && Uptime == 0) return true;
        return false;
    }
};
// @lc code=end

