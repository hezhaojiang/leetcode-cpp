/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> history;
        while(n != 1) {
            int m = n, sum = 0, s = 0;
            while (m) {
                s = m % 10;
                sum += s * s;
                m /= 10;
            }
            if (history.count(sum)) return false;
            else n = sum, history[sum] = 1;
        }
        return true;
    }
};
// @lc code=end

