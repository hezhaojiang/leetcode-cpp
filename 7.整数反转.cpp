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
        int max = 0x7FFFFFFF;
        int min = 0x80000000;
        long new_x = 0;
        while(x)
        {
            new_x = new_x * 10 + x % 10;
            x /= 10;
        }
        cout << new_x << endl;
        if(new_x > max || new_x < min)
        {
            return 0;
        }
        return new_x;
    }
};
// @lc code=end

int main()
{
    int ret;
    Solution slove;
    ret = slove.reverse(123);
    cout << ret << endl;
    return 0;
}