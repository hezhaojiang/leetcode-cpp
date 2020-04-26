/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include<vector>
#include<stack>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stackCs;
        for(auto c : s)
        {
            if(c == '(' || c == '[' || c == '{')
                stackCs.push(c);
            else if(c == ')')
                if(stackCs.empty() || stackCs.top() != '(') return false;
                else stackCs.pop();
            else if(c == ']')
                if(stackCs.empty() || stackCs.top() != '[') return false;
                else stackCs.pop();
            else if(c == '}')
                if(stackCs.empty() || stackCs.top() != '{') return false;
                else stackCs.pop();
        }
        if(stackCs.empty()) return true;
        else return false;
    }
};
// @lc code=end

