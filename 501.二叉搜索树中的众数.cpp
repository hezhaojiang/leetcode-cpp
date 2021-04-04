/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
private:
    vector<int> result;
    int last;
    int count;
    int maxCount;
    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->left);
        if (count == 0 || last == node->val) count++;
        else count = 1;
        last = node->val;
        if (count == maxCount) result.push_back(last);
        else if (count > maxCount) {
            result = vector<int> {last};
            maxCount = count;
        }
        dfs(node->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        dfs(root);
        return result;
    }
};
// @lc code=end

