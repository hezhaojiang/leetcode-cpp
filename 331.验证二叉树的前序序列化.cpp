/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */
#include<string>
#include<sstream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool decode(stringstream& ss)
    {
        string item;
        if (getline(ss, item, ','))
        {
            if (item[0] == '#') return true;
            else return decode(ss) && decode(ss);
        }
        return false;
    }
    bool isValidSerialization(string preorder) {
        bool result;
        string item;
        stringstream ss(preorder);
        result = decode(ss);
        if(getline(ss, item, ',')) return false;
        else return result;
    }
};
// @lc code=end
int main()
{
    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    Solution solve;
    solve.isValidSerialization(s);
    return 0;
}
