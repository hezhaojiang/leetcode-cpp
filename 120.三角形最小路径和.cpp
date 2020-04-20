/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> Sum;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        Sum.resize(triangle.size());
        for(auto line : triangle)
        {
            int last = 0;
            for(int i = 0; i < line.size(); i++)
            {
                int temp = Sum[i];
                if(i == 0) Sum[i] = Sum[i] + line[i];
                else if(i == line.size() - 1) Sum[i] = last + line[i];
                else Sum[i] = min(Sum[i], last) + line[i];
                last = temp;
            }
        }
        int minRes = INT_MAX;
        for(auto a : Sum)
            if(a < minRes) minRes = a;
        return minRes;
    }
};
// @lc code=end

