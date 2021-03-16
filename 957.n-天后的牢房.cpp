/*
 * @lc app=leetcode.cn id=957 lang=cpp
 *
 * [957] N 天后的牢房
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int size = cells.size();
        int state = 0;
        for (int i = 0; i < size; i++) {
            state <<= 1;
            if (cells[i]) state |= 0x1;
        }
        vector<int> memo;
        for (int i = 0; i < n; i++) {
            state = ~(state << 1 ^ state >> 1) & 0x7E;
            if (!memo.empty() && memo[0] == state) break;
            memo.push_back(state);
        }
        int result = memo[(n - 1) % memo.size()];
        vector<int> res(size, 0);
        for (int i = 0; i < size; i++) {
            if (result & (0x1 << (size - 1 - i))) res[i] = 1;
        }
        return res;
    }
};
// @lc code=end
