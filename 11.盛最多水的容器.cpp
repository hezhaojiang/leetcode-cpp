/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        for(int i = 0, j = height.size() - 1; i != j;)
        {
            maxA = max(maxA, (j - i) * min(height[i], height[j]));
            if(height[i] > height[j]) j--;
            else i++;
            
        }
        return maxA;
    }
};
// @lc code=end

