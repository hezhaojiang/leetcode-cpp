/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */
#include <sstream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValidSerialization(string preorder) {
        string s;
        int n = preorder.length();
        for (int i = 0; i < n; i++) {
            if (preorder[i] == ',') continue;
            if (i > 0 && isdigit(preorder[i]) && isdigit(preorder[i - 1])) continue;
            s.push_back(preorder[i]);
            int len = s.length();
            while (len >= 3 && 
                s[len - 1] == '#' && s[len - 2] == '#' && s[len - 3] != '#') {
                s.pop_back(), s.pop_back(), s[len - 3] = '#';
                len = s.length();
            }
        }
        return s == "#";
    }
};
// @lc code=end
int main() {
    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    Solution solve;
    solve.isValidSerialization(s);
    return 0;
}
