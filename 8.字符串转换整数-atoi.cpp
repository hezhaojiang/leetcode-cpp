/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int symbol = 1;
        int status = 0;
        
        for(auto c : str)
        {
            switch(status)
            {
                case 0:
                    if(isspace(c)) break;
                    else if(c == '-') { symbol = -1; status = 1; }
                    else if(c == '+') { symbol = 1; status = 1; }
                    else if(isdigit(c)) { result = c - '0'; status = 2; }
                    else status = -1;\
                    break;
                case 1:
                    if(isdigit(c)) { result = c - '0'; status = 2; }
                    else status = -1;
                    break;
                case 2:
                    if(isdigit(c)) 
                    { 
                        result = result * 10 + c - '0';
                        result = symbol==1?min(result, (long)INT_MAX):min(result, -(long)INT_MIN);
                    }
                    else status = -1;
                    break;
                default:
                    return result * symbol;
            }
        }
        return result * symbol;
    }
};
// @lc code=end
int main()
{
    Solution solve;
    cout << solve.myAtoi("43") << endl;
    return 0;
}
