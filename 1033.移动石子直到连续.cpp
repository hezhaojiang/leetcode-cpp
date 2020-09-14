/*
 * @lc app=leetcode.cn id=1033 lang=cpp
 *
 * [1033] 移动石子直到连续
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min(a, min(b, c));
        int z = max(a, max(b, c));
        int y = a ^ b ^ c ^ x ^ z;
        vector<int> moves(2, 0);
        moves[1] = z - x - 2;
        if (y - x == 1 && z - y == 1) return moves;
        if (y - x <= 2 || z - y <= 2) {moves[0] = 1; return moves;}
        else {moves[0] = 2; return moves;}
    }
};
// @lc code=end

