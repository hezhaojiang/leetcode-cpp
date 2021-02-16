/*
 * @lc app=leetcode.cn id=1707 lang=cpp
 *
 * [1707] 与数组中元素的最大异或值
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class BitTrie {
public:
    int minValue = INT_MAX;
    BitTrie* next[2] = {nullptr};
    void insert(int number) {
        BitTrie* root = this;
        for (int i = 30; i >= 0; i--) {
            int mark = (number >> i) & 1;
            if (root->next[mark] == nullptr) root->next[mark] = new BitTrie();
            root = root->next[mark];
            root->minValue = min(root->minValue, number);
        }
    }
    int findmaxXOR(int number) {
        BitTrie* root = this;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            int mark = (number >> i) & 1;
            int findmark = mark ^ 1;
            if (root->next[findmark] == nullptr) {
                if (root->next[mark] == nullptr) return -1;
                else root = root->next[mark];
            }
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        BitTrie bt;
        int N = queries.size();
        vector<int> res(N, 0);
        int pos = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N; i++) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [](auto& a, auto& b) { return a[1] < b[1]; });

        for (auto & q : queries) {
            // 构建字典树
            while (pos < nums.size() && nums[pos] <= q[1]) bt.insert(nums[pos++]);
            // 通过字典树查找最大异或值
            res[q[2]] = bt.findmaxXOR(q[0]);
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solve;
    vector<int> nums{536870912, 0, 534710168, 330218644, 142254206};
    vector<vector<int>> queries{{214004, 404207941}};
    for (auto& r : solve.maximizeXor(nums, queries)) {
        cout << r << endl;
    }
    return 0;
}
