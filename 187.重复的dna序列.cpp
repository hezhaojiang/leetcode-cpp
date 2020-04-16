/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<string, int> mapSi;
        for(int i = 0; i + 10 <= s.length(); i++)
        {
            string str = s.substr(i,10);
            if(mapSi.find(str) != mapSi.end())
            {
                if(mapSi[str]++ == 1) result.emplace_back(str);
            }
            else mapSi[str] = 1;
            //result.emplace_back(str);
        }
        return result;
    }
};
// @lc code=end

