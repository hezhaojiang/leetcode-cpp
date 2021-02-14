/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */
#include<vector>
#include<numeric>
using namespace std;
// @lc code=start
class Solution {
private:
    bool check(vector<int>& weights, int D, int can) {
        int count = 1, cur = 0;
        for (auto w : weights) {
            if (w > can) return false;
            if (can - cur < w) {
                count++;
                cur = w;
            } else cur += w;
        }
        return count <= D;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 1, r = accumulate(weights.begin(), weights.end(), 0);
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(weights, D, mid)) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};
// @lc code=end

