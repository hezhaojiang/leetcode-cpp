/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 */
#include <unordered_map>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<int, int> mp;
    int GetTreeSum(TreeNode* root) {
        if (!root) return 0;
        root->val += GetTreeSum(root->left) + GetTreeSum(root->right);
        mp[root->val]++;
        return root->val;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        GetTreeSum(root);
        int maxValue = 0;
        for (auto& m : mp) maxValue = max(m.second, maxValue);
        vector<int> res;
        for (auto& m : mp)
            if (maxValue == m.second) res.push_back(m.first);
        return res;
    }
};
// @lc code=end
