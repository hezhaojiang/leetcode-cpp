/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class BitTrie {
public:
    BitTrie* next[2] = {nullptr};
    void insert(int number) {
        BitTrie* root = this;
        for (int i = 30; i >= 0; i--) {
            int mark = (number >> i) & 1;
            if (root->next[mark] == nullptr) root->next[mark] = new BitTrie();
            root = root->next[mark];
        }
    }
    int findmaxXOR(int number) {
        BitTrie* root = this;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            int mark = (number >> i) & 1;
            int findmark = mark ^ 1;
            if (root->next[findmark] == nullptr) root = root->next[mark];
            else {
                root = root->next[findmark];
                res |= 1 << i;
            }
        }
        return res;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        BitTrie bt;
        int res = 0;
        // 构建字典树
        for (auto n : nums) bt.insert(n);
        // 通过字典树查找每个数的最大异或值
        for (auto n : nums) res = max(res, bt.findmaxXOR(n));
        return res;
    }
};
// @lc code=end
