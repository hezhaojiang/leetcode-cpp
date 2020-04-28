/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include<vector>
#include<stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
#ifdef SOLUTION1
        int rain = 0;
        for(int i = 0; i < height.size(); i++)
        {
            int leftmax = 0;
            int rightmax = 0;
            for(int j = 0; j < height.size(); j++)
            {
                if(j < i && leftmax < height[j]) leftmax = height[j];
                if(j > i && rightmax < height[j]) rightmax = height[j];
            }
            int sq = min(leftmax, rightmax) - height[i];
            if(sq > 0) rain += sq;
        }
        return rain;
#endif
#ifdef SOLUTION2
        /* 双指针 */
        int rain = 0;
        int leftmax = 0;
        int rightpos = 0;
        int rightmax = 0;
        for(int i = 0; i < height.size(); i++)
        {
            if(height[i] >= leftmax)
            {
                leftmax = height[i];
                continue;
            }
            if(i > rightpos)
            {
                rightmax = 0;
                for(int j = i + 1; j < height.size(); j++)
                {
                    if(rightmax < height[j]) 
                    {
                        rightmax = height[j];
                        rightpos = j;
                    }
                }
            }
            
            int sq = min(leftmax, rightmax) - height[i];
            if(sq > 0) rain += sq;
        }
        return rain;
#endif
#define SOLUTION3
#ifdef SOLUTION3
        /* 单调栈 */
        int rain = 0;
        stack<int> wall;
        for(int i = 0; i < height.size(); i++)
        {
            while(!wall.empty() && height[i] >= height[wall.top()])
            {
                int blow = height[wall.top()];
                wall.pop();
                if(wall.empty()) break;
                rain += (min(height[i], height[wall.top()]) - blow) * (i - wall.top() - 1);
                
            }
            wall.push(i);
        }
        return rain;
#endif
    }
};
// @lc code=end
int main()
{
    Solution solve;
    int ret = solve.trap(vector<int>{1,0,1});
    return 0;
}


