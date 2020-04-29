/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include<vector> 
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
#ifdef BAOLI
        /* 暴力法 计算每个位置的最大举行面积 */
        int result = 0;
        /* 引入 map 对已经计算过的数据进行记录 防止重复操作 */
        unordered_map<int, int> mapHR; // 保存对应高度计算到的最右位置
        for(int i = 0; i < heights.size(); i++)
        {
            if(mapHR.find(heights[i]) != mapHR.end() && mapHR[heights[i]] >= i) continue;
            int leftpos = i;
            int rightpos = i;
            /* 找到左侧第一个低于当前高度的 */
            for(int j = i - 1; j >= 0; j--)
            {
                if(heights[j] < heights[i]) break;
                leftpos = j;
            }
            /* 找到右侧第一个低于当前高度的 */
            for(int j = i + 1; j < heights.size(); j++)
            {
                if(heights[j] < heights[i]) break;
                rightpos = j;
            }
            mapHR[heights[i]] = rightpos; // 保存对应高度计算到的最右位置
            result = max(result, (rightpos - leftpos + 1) * heights[i]);
        }
        return result;
#endif
#ifdef STACK
        /* 单调栈法 单调递增栈 */
        int result = 0;
        stack<int> incStack;
        int Area = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            while(!incStack.empty() && heights[incStack.top()] > heights[i])
            {
                int high = incStack.top();
                incStack.pop();
                if(incStack.empty()) Area = heights[high] * i;
                else Area = heights[high] * (i - incStack.top() - 1);
                result = max(result, Area);
            }
            incStack.push(i);
        }
        while(!incStack.empty())
        {
            int high = incStack.top();
            incStack.pop();
            if(incStack.empty()) Area = heights[high] * heights.size();
            else Area = heights[high] * (heights.size() - incStack.top() - 1);
            result = max(result, Area);
        }
        return result;
#endif
    }
};
// @lc code=end

