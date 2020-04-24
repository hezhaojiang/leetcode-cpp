/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include<string>
#include<map>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    map<char, string> tel;
    string item;
    vector<string> result;
    void dfs(string& digits, int index)
    {
        if(index >= digits.length())
        {
            result.push_back(item);
            return;
        }
        for(auto c : tel[digits[index]])
        {
            item = item + c;
            dfs(digits, index + 1);
            item = item.substr(0, item.length() - 1);
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        tel['2'] = "abc";
        tel['3'] = "def";
        tel['4'] = "ghi";
        tel['5'] = "jkl";
        tel['6'] = "mno";
        tel['7'] = "pqrs";
        tel['8'] = "tuv";
        tel['9'] = "wxyz";
        if(digits.length() == 0) return vector<string>{};
        dfs(digits, 0);
        return result;
    }
};
// @lc code=end

