/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int N = cardPoints.size();
        int point = 0;
        for (int i = 0; i < k; i++) point += cardPoints[i];
        int left = k, right = N, maxpoint = point;
        while (left > 0) {
            left--, right--;
            point += cardPoints[right] - cardPoints[left];
            maxpoint = max(point, maxpoint);
        }
        return maxpoint;
    }
};
// @lc code=end

