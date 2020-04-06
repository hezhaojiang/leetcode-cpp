/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */
#include<string>
#include<vector>
// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.length(); 
        if (len == k) 
        {
            return "0";
        }

        int i = 1;
        int eraselen = 0;
        num = "0" + num + "0";
        while(eraselen < k)
        {
            if(num[i] > num[i + 1])
            {
                num.erase(i, 1);
                eraselen++;
                i--;
            }
            else
            {
                i++;
            } 
        }

        i = 0;
        while(num[i] == '0')
        {
            num.erase(i, 1);
        }
        if(num == "")
        {
            return "0";
        }
        num.erase(num.length() - 1);
        return num;
    }
};
// @lc code=end

