/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
bool cmp(vector<int> &a, vector<int> &b){
    return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), cmp);
        vector<vector<int>> res;
        for (int i = 0; i < K; i++) res.push_back(points[i]);
        return res;
    }
};
// @lc code=end

