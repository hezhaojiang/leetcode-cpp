/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> battle(2, 0);
        for (auto bill : bills) {
            if (bill == 5) battle[0]++;
            else if (bill == 10) {
                if (battle[0]-- < 0) return false;
                battle[1]++;
            }
            else if (bill == 20) {
                if ((battle[1] == 0 && battle[0] < 3) || battle[0] < 1)
                    return false;
                if (battle[1] > 0) { battle[1]--; battle[0]--; }
                else { battle[0] -= 3; }
            }
        }
        return true;
    }
};
// @lc code=end

