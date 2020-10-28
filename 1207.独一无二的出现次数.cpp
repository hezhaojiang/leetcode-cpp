/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> tableNum;
        unordered_map<int,int> tableCot;
        for (auto a : arr) {
            if (tableNum.find(a) != tableNum.end()) tableNum[a]++;
            else tableNum[a] = 1;
        }
        for (auto & n : tableNum) {
            if (tableCot.find(n.second) != tableCot.end()) tableCot[n.second]++;
            else tableCot[n.second] = 1;
        }
        for (auto & c : tableCot) if (c.second != 1) return false;
        return true;
    }
};
// @lc code=end

