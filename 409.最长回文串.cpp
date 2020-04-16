/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        int flag = 0;
        int result = 0;
        int item[128] = {0};
        for(auto a : s) item[a]++;
        for(auto i : item)
        {
            if(i % 2 == 0) result += i;
            else
            {
                result += i - 1;
                flag = 1;
            }
        }
        return result + flag;
    }
};
// @lc code=end

