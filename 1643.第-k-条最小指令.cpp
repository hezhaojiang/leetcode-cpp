/*
 * @lc app=leetcode.cn id=1643 lang=cpp
 *
 * [1643] 第 K 条最小指令
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> nCK;

public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int h = destination[1];
        int v = destination[0];
        nCK.resize(31, vector<int>(31, 0));
        nCK[0][0] = 1;
        for (int i = 1; i < 31; i++) {
            nCK[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                nCK[i][j] = nCK[i - 1][j - 1] + nCK[i - 1][j];
            }
        }
        string res;
        for (int i = 0, count = h + v; i < count; i++) {
            if (h > 0) {
                int o = nCK[h + v - 1][h - 1];
                if (k > o) {
                    k -= o;
                    res += 'V';
                    v--;
                }
                else {
                    res += 'H';
                    h--;
                }
            }
            else {
                res += 'V';
                v--;
            }
        }
        return res;
    }
};
// @lc code=end
