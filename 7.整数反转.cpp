/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int new_x = 0;
        while(x)
        {
            new_x = new_x * 10 + x % 10;
            x /= 10;
        }
        return new_x;
    }
};
// @lc code=end

int main()
{
    int ret;
    Solution slove;
    ret = slove.reverse(1534236469);
    cout << ret << endl;
    return 0;
}