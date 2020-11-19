/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int curOil = 0;
        int needOil = 0;
        for (int i = 0; i < gas.size(); i++) {
            curOil = curOil + gas[i] - cost[i];
            if (curOil < 0) {
                needOil -= curOil;
                curOil = 0;
                start = i + 1;
            }
        }
        if(curOil >= needOil) return start;
        else return -1;
    }
};
// @lc code=end

