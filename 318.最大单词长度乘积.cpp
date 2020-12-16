/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;
        unordered_map<string, int> ump;
        for (auto & word : words) {
            int a = 0;
            for (auto c : word) a |= 1 << (c - 'a');
            ump[word] = a;
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                if ((ump[words[i]] & ump[words[j]]) != 0) continue;
                result = max(result, static_cast<int>(words[i].length() * words[j].length()));
            }
        }
        return result;
    }
};
// @lc code=end

