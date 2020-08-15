/*
 * @lc app=leetcode.cn id=546 lang=cpp
 *
 * [546] 移除盒子
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<vector<int>>> index;
public:
    int removeBoxes(vector<int> &boxes){
        if (boxes.empty()) return 0;
        const int N = boxes.size() + 1;
        index.resize(N, vector<vector<int>>(N, vector<int>(N, 0)));

        /* 遍历求得所有 index[x][y][a] 的值 */
        for (int len = 1; len <= boxes.size(); ++len) {
            for (int x = 0; x + len <= boxes.size(); ++x) {
                const int y = x + len - 1;
                for (int a = 0; a <= x; ++a) { /* 只需求 a <= x 部分 */
                    int &ans = index[x][y][a], e = 0, f = 0;

                    /* 求出 A[x] 所在数据块 A[x-a..e-1] */
                    for (e = x + 1; e <= y; ++e) {
                        if (boxes[e] != boxes[x]) break;
                    }

                    /* 直接消除 A[x-a..e-1] 位的数据块 + 消除 A[e..y] 的剩余数据 */
                    ans = max(ans, (a + e - x) * (a + e - x) + index[e][y][0]);

                    /* 遍历每一块与 A[x] 值相等的数据块，A[f..] */
                    for (f = e; f <= y; ++f) {
                        if (boxes[f] == boxes[x] && boxes[f - 1] != boxes[x]) {
                            /* 消除 A[e..f-1] + 消除 A[x-a..e-1,f..y] */
                            ans = max(ans, index[e][f - 1][0] + index[f][y][e - x + a]);
                        }
                    }
                }
            }
        }
        return index[0][boxes.size() - 1][0];
    }
};
// @lc code=end
