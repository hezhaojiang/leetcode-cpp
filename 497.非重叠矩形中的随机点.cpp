/*
 * @lc app=leetcode.cn id=497 lang=cpp
 *
 * [497] 非重叠矩形中的随机点
 */
#include <random>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> sum;
    vector<vector<int>>::iterator begin, end;

public:
    Solution(vector<vector<int>>& rects) {
        sum.resize(1, 0);
        begin = rects.begin();
        end = rects.end();
        for (auto& r : rects) {
            int points = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            sum.push_back(sum.back() + points);
        }
    }
    
    vector<int> pick() {
        // 先随机选择矩形
        int t = rand() % sum.back();
        int index = upper_bound(sum.begin(), sum.end(), t) - sum.begin() - 1;
        // 然后在矩形内随机选点
        vector<int>& r = *(begin + index);
        int w = rand() % (r[2] - r[0] + 1);
        int h = rand() % (r[3] - r[1] + 1);
        return vector{r[0] + w, r[1] + h};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end

