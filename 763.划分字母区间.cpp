/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        vector<int> last(26, 0);
        for (int i = 0; i < S.length(); i++) last[S[i] - 'a'] = max(last[S[i] - 'a'], i);
        int start = 0, end = 0;
        for (int i = 0; i < S.length(); i++) {
            end = max(end, last[S[i] - 'a']);
            if (end == i) {
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};
// @lc code=end

