/*
 * @lc app=leetcode.cn id=1592 lang=cpp
 *
 * [1592] 重新排列单词间的空格
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string reorderSpaces(string text) {
        bool lastisspace = true;
        int spacenum = 0;
        int wordnum = 0;
        string s;
        for (auto c : text) {
            if (c == ' ') {spacenum++; lastisspace = true;}
            else if(lastisspace) {wordnum++; lastisspace = false;}
        }
        int avcspace;
        int resspace;
        if (wordnum == 0) return text;
        else if (wordnum == 1) {
            avcspace = 0;
            resspace = spacenum;
        }
        else {
             avcspace = spacenum / (wordnum - 1);
             resspace = spacenum % (wordnum - 1);
        }
        
        for (auto c : text) {
            if (c == ' ') {lastisspace = true;}
            else {
                if(lastisspace && !s.empty()) s.append(avcspace, ' ');
                s += c; 
                lastisspace = false;
            }
                
        }
        s.append(resspace, ' ');
        //turn to_string(resspace);
        return s;
    }
};
// @lc code=end

