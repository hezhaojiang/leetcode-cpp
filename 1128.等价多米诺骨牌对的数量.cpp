/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> num(100);
        int ret = 0;
        for (auto& it : dominoes) {
            int val = it[0] < it[1] ? it[0] * 10 + it[1] : it[1] * 10 + it[0];
            ret += num[val];
            num[val]++;
        }
        return ret;
    }
};
// @lc code=end

