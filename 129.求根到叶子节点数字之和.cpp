/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
 */
#include<vector>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    vector<int> item;
    int result;
    void add_item_to_result() {
        int num = 0;
        for (auto a : item) num = num * 10 + a;
        result += num;
        return;
    }
public:
    void preOrder(TreeNode* root) {
        if(!root) return;
        item.push_back(root->val);
        if(!root->left && !root->right) add_item_to_result();
        preOrder(root->left);
        preOrder(root->right);
        item.pop_back();
        return;
    }
    int sumNumbers(TreeNode* root) {
        preOrder(root);
        return result;
    }
};
// @lc code=end

