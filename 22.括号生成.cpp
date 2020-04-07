/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    vector<string> result;
public:
    void backtracking(int left, int right, string item, vector<string>& result)
    {
        if(right == 0)
        {
            result.push_back(item);
            return;
        }
        if(left != 0)
        {
            item = item + "(";
            backtracking(left - 1, right, item, result);
            item = item.substr(0, item.length() - 1);
        }
        if(left < right)
        {
            item = item + ")";
            backtracking(left, right - 1, item, result);
        }
        return;
    }
    vector<string> generateParenthesis(int n) 
    {
        string item = "";
        backtracking(n, n, item, result);
        return result;
    }
};
// @lc code=end

