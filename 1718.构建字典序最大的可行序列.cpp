/*
 * @lc app=leetcode.cn id=1718 lang=cpp
 *
 * [1718] 构建字典序最大的可行序列
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    bool dfs(vector<int>& res, int pos, vector<int>& use) {
        for (int i = use.size() - 1; i > 0; i--) {
            if (use[i] != 0) continue;
            // 找到没有使用的最大数字 填充数组
            if (i == 1) res[pos] = use[i] = i;
            else if (pos + i < res.size() && res[pos + i] == 0) res[pos] = res[pos + i] = use[i] = i;
            else continue;
            // 找到下一个空白位置并深度优先搜索
            int nextpos = pos;
            while (res[nextpos] != 0) if (++nextpos == res.size()) return true;
            if (dfs(res, nextpos, use)) return true;
            // 恢复数组
            if (i == 1) res[pos] = use[i] = 0;
            else res[pos] = res[pos + i] = use[i] = 0;
            
        }
        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {
        int N = 2 * n - 1;
        vector<int> res(N, 0);
        vector<int> use(n + 1, 0);
        dfs(res, 0, use);
        return res;
    }
};
// @lc code=end

int main() {
    Solution solve;
    solve.constructDistancedSequence(9);
    return 0;
}
