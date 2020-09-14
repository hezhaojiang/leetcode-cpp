/*
 * @lc app=leetcode.cn id=1503 lang=cpp
 *
 * [1503] 所有蚂蚁掉下来前的最后一刻
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lastMoment = 0;
        for (int ant : left) lastMoment = max(lastMoment, ant);
        for (int ant : right) lastMoment = max(lastMoment, n - ant);
        return lastMoment;
    }
};
// @lc code=end

