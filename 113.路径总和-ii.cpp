/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */
#include<vector>
#include<stack>
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
    vector<int> item;
    vector<vector<int>> result;
public:
    void preOrder(TreeNode* root, int target) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (root->val == target) {
                item.push_back(root->val);
                result.push_back(item);
                item.pop_back();
            }
            return;
        }
        item.push_back(root->val);
        preOrder(root->left, target - root->val);
        preOrder(root->right, target - root->val);
        item.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        preOrder(root, sum);
        return result;
    }
};
// @lc code=end

