/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> mp;
        for (auto a : answers) mp[a]++;
        for (auto& [x, y] : mp) res += (x + y) / (x + 1) * (x + 1);
        return res;
    }
};
// @lc code=end

