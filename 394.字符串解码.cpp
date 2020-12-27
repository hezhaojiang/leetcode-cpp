/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
using namespace std;

// @lc code=start
typedef struct {
    int num;
    string str;
} pie;

class Solution {
public:
    int decodeString(string s, int i, string res) {
        stack<pie> strStack;
        string result = "";
        pie temp = {0, ""};

        for (auto i : s) {
            if (i >= '0' && i <= '9') temp.num = 10 * temp.num + (i - '0');
            else if (i == '[') {
                strStack.push(temp);
                temp.num = 0;
                temp.str = "";
            } else if(i == ']') {
                string strrep = "";
                int count = strStack.top().num;
                for(int i = 0; i < count; i++) strrep = temp.str + strrep;
                strrep = strStack.top().str + strrep;
                strStack.pop();
                temp.str = strrep;
            } else temp.str = temp.str + i;
        }
        result = temp.str;
    }
};
// @lc code=end

