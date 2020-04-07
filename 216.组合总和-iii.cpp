 /*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> item;
    vector<vector<int>> result;
public:
    void backtrack(int left, int begin, int target, int curNum)
    {
        if(target == curNum && left == 0)
        {
            result.push_back(item);
            return;
        }
        if(begin <= 9 && curNum < target)
        {
            if(curNum + begin > target)
            {
                return;
            }
            item.push_back(begin);
            backtrack(left - 1, begin + 1, target, curNum + begin);
            item.pop_back();
            backtrack(left, begin + 1, target, curNum);
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtrack(k, 1, n, 0);
        return result;
    }
};
// @lc code=end

