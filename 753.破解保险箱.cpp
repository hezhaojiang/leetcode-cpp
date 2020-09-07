/*
 * @lc app=leetcode.cn id=753 lang=cpp
 *
 * [753] 破解保险箱
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int node = 0;
    void dfs(vector<int> & side, int n, int k, int i, string& res) {
        int currNode = i % node;
        for (int j = 0; j < k; ++j) {
            int t = currNode * k + j;
            if (!side[t]++) {
                dfs(side, n, k, t, res);
                res += j + '0';
            }
        }
    }
    string crackSafe(int n, int k) {
        node = pow(k, n - 1);       /* 节点个数 */
        vector<int> side(node * k, 0); /* 边的个数，用来指示每条边是否遍历过 */
        string res;
        dfs(side, n, k, 0, res);    /* 从全 0 节点开始寻找 */
        res.append(n - 1, '0');
        return res;
    }
};
// @lc code=end

