/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */
#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int calPathDeep(string& s)
    {
        int deep = 0;
        int start;
        while(start = s.find("\t"), start != std::string::npos)
        {
            deep++;
            s.erase(start, 1);
        }
        return deep;
    }
    void split(string& s, vector<string>& v, string c)
    {
        int start, end;
        start = 0;
        end = s.find(c);
        while(end != std::string::npos)
        {
            string tmp = s.substr(start, end-start);
            if(tmp != "")
            {
                v.push_back(s.substr(start, end-start));
            }
            start = end + c.size();
            end = s.find(c, start);
        }
        if(start != s.length())
            v.push_back(s.substr(start));
    }
    int lengthLongestPath(string input) {
        int maxlenth = 0;
        int curlenth = 0;
        vector<string> input_list;
        stack<string> Stack_path;
        stack<int> Stack_lenth;

        split(input, input_list, "\n");
        for(string p : input_list)
        {
            int deep = calPathDeep(p);
            while(deep != Stack_path.size())
            {
                Stack_path.pop();
                Stack_lenth.pop();
            }
            if(Stack_lenth.empty())
            {
                curlenth = p.length();
            }
            else
            {
                curlenth = Stack_lenth.top() + p.length() + 1;
            }       
            Stack_path.push(p);
            Stack_lenth.push(curlenth);

            if(Stack_lenth.top() > maxlenth 
                && string::npos != Stack_path.top().find("."))
            {
                maxlenth = Stack_lenth.top();
            }
        }
        return maxlenth;
    }
};
// @lc code=end
int main()
{
    Solution solve;
    string s = "a ";
    int result = solve.lengthLongestPath(s);
    cout << s <<endl;
    cout << "result : " << result <<endl;
    return 0;
}
