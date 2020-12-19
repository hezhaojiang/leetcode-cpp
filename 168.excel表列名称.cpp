/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0) {
            res.push_back('A' + (n - 1) % 26);
            n = (n - 1) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
int main()
{
    Solution solve;
    solve.convertToTitle(701);
    return 0;
}
