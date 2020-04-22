/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty()) return s;
        int offset = max(1, 2 * numRows - 2);
        string result;
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; ; j++)
            {
                if(i + offset * j < s.length()) 
                    result += s[i + offset * j];
                else break;
                if(i == 0 || i == numRows - 1) continue;
                if(offset * (j + 1) - i < s.length()) 
                    result += s[offset * (j + 1) - i];
                else break;
            }
        }
        return result;
    }
};
// @lc code=end

