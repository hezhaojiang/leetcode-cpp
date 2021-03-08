/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        unordered_map<int, vector<int>> mp;
        vector<string> res;
        for (int i = 0; i < 60; i++) mp[__builtin_popcount(i)].push_back(i);
        for (int i = 0; i <= num; i++) {
            for (auto hour : mp[i]) {
                if (hour > 11) continue;
                for (auto m : mp[num - i]) {
                    res.push_back(to_string(hour) + ":" + 
                        (m < 10 ? "0" + to_string(m) : to_string(m)));
                }
            }
        }
        return res;
    }
};
// @lc code=end
