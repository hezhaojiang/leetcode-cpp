/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include<string> 
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.length() - 1; i < j; i++, j--)
        {
            while(i < j && !isalnum(s[i])) i++;
            while(i < j && !isalnum(s[j])) j--;
            if(i <= j)
                if(tolower(s[i]) == tolower(s[j]))
                    continue;
                else
                    return false;
        }
        return true;
    }
};
// @lc code=end
int main()
{
    Solution solve;
    solve.isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}
