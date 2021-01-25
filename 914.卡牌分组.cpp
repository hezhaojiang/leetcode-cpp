/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 */
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> deck2num;
        int res = 0;
        for (auto d : deck) deck2num[d]++;
        for (auto &[d, n] : deck2num) {
            if (res == 0) res = n;
            else res = __gcd(res, n);
        }
        return res > 1;
    }
};
// @lc code=end

