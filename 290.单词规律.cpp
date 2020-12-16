/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */
#include<map>
#include<string>
#include<sstream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        char index[26] = { 0 };
        stringstream ss(str);
        map<string, char> mapSc;
        string s;
        for (auto c : pattern) {
            s.clear();
            if (!(ss >> s)) return false;
            if (mapSc.find(s) == mapSc.end()) {
                if (index[c - 'a'] != 0) return false;
                mapSc[s] = c;
                index[c - 'a'] = 1;
            }
            else if(c != mapSc[s]) return false;
        }
        if(ss >> s) return false;
        return true;
    }
};
// @lc code=end
int main()
{
    Solution solve;
    solve.wordPattern("abba", "dog cat cat dog");
    return 0;
}

