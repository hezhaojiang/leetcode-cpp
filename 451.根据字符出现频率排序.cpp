/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */
#include<string>
#include<vector>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        vector<int> count(128, 0);
        for (auto c : s) count[c]++;
        priority_queue<pair<int, char>> Q;
        for (int i = 0; i < 128; i++)
            if (count[i]) Q.emplace(count[i], i);
        string res;
        while (!Q.empty()) {
            auto& c = Q.top();
            res.append(c.first, c.second);
            Q.pop();
        }
        return res;
    }
};
// @lc code=end

