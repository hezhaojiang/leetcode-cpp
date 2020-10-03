/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除与获得点数
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> counts;
        for (auto num : nums) {
            if (num >= counts.size()) counts.resize(num + 1, 0);
            counts[num]++;
        }

        vector<int> money(1, 0);
        for(int i = 0; i < counts.size(); i++) {
            if(i == 0) money.push_back(counts[i] * i);
            else money.push_back(max(money[i - 1] + counts[i] * i, money[i]));
        }
        return money.back();
    }
};
// @lc code=end

