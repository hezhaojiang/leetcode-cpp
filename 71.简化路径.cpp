/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include<vector>
#include<stack>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
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
        {
            v.push_back(s.substr(start));
        }
    }
    string simplifyPath(string path) {
        std::stack<string> Stack;
        std::vector<string> path_list;
        string result;
        split(path, path_list, "/");
        for(string p : path_list)
        {
            if(!p.compare(".."))
            {
                if(!Stack.empty())
                {
                    Stack.pop();
                }
            }
            else if(!p.compare("."))
            {
                continue;
            }
            else
            {
                Stack.push(p);
            }
        }
        while(!Stack.empty())
        {
            result = "/" + Stack.top() + result;
            Stack.pop();
        }
        if(result.empty())
        {
            result = "/";
        }
        return result;
    }
};
// @lc code=end

