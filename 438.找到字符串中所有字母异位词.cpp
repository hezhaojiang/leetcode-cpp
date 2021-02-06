/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int N = s.size(); 
        int M = p.size();
        int left = 0, right = 0;
        int matchlength = 0, otherlength = 0;
        vector<int> nums(26, 0);
        vector<int> res;
        for (auto c : p) nums[c - 'a']--;
        while (right < N) {
            if (nums[s[right] - 'a']++ < 0) matchlength++;
            else otherlength++;
            if (right++ >= M) {
                if (--nums[s[left++] - 'a'] < 0) matchlength--;
                else otherlength--;
            }
            if (right >= M && matchlength == M && otherlength == 0) res.push_back(left);
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution solve;
    solve.findAnagrams("cbaebabacd", "abc");
    return 0;
}

