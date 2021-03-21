/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <stack>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a = 0;
        std::stack<int> bolan;
        for (int i = 0; i < tokens.size(); i++) {
            if (!tokens[i].compare("+")) {
                a = bolan.top(), bolan.pop();
                a += bolan.top(), bolan.pop();
                bolan.push(a);
            } else if (!tokens[i].compare("-")) {
                a = bolan.top(), bolan.pop();
                a = bolan.top() - a, bolan.pop();
                bolan.push(a);
            } else if (!tokens[i].compare("*")) {
                a = bolan.top(), bolan.pop();
                a *= bolan.top(), bolan.pop();
                bolan.push(a);
            } else if (!tokens[i].compare("/")) {
                a = bolan.top(), bolan.pop();
                a = bolan.top() / a, bolan.pop();
                bolan.push(a);
            } else {
                bolan.push(atoi(tokens[i].c_str()));
            }
        }
        return bolan.top();
    }
};
// @lc code=end
