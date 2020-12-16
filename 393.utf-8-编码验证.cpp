/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 */
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int N = data.size();
        int need_10 = 0;
        for (int i = 0; i < N; i++) {
            if (need_10) {
                if ((data[i] & 0xC0) != 0x80) return false;
                need_10--;
            }
            else {
                 if ((data[i] & 0x80) == 0) continue;
                 else if ((data[i] & 0xE0) == 0xC0) need_10 = 1;
                 else if ((data[i] & 0xF0) == 0xE0) need_10 = 2;
                 else if ((data[i] & 0xF8) == 0xF0) need_10 = 3;
                 else return false;
            }
        }
        if (need_10) return false;
        else return true;
    }
};
// @lc code=end

