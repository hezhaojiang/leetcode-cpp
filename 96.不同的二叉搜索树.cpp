/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
#include<vector>
using namespace std;
// @lc code=start
static vector<int> result;
class Solution {
public:
    int numTrees(int n) {
        if(n < result.size()) return result[n];
        if(0 == result.size())
        {
            result.push_back(1);
            result.push_back(1);
            result.push_back(2);
        }
        int i = result.size();
        for(; i <= n; i++)
        {
            int item = 0;
            for(int j = 0; j < i; j++)
            {
                item += result[j] * result[i - 1 - j];
            }
            result.push_back(item);
        }
        return result[n];
    }
};
// @lc code=end

