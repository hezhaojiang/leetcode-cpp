/*
 * @lc app=leetcode.cn id=932 lang=cpp
 *
 * [932] 漂亮数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> res;
    void dfs(int l, int r) {
        if (l == r) {
            res[l] = 1;
            return;
        }
        int c = r - l + 1;     // 1 到 c 有 c >> 1 个偶数 c + 1 >> 1 个奇数
        int odd = c + 1 >> 1;  // 奇数个数
        dfs(l, l + odd - 1);
        dfs(l + odd, r);
        for (int i = 0; i < odd; i++) res[l + i] = (res[l + i] << 1) - 1;
        for (int i = odd; i < c; i++) res[l + i] <<= 1;
    }

public:
    vector<int> beautifulArray(int N) {
        res.resize(N, 0);
        dfs(0, N - 1);
        return res;
    }
};
// @lc code=end

int main() {
    Solution so;
    so.beautifulArray(4);
    return 0;
}
