/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */
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
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class BSTIterator {
private:
    vector<TreeNode*> item;

public:
    BSTIterator(TreeNode* root) {
        while (root) {
            item.push_back(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* ret = item.back();
        int result = ret->val;
        item.pop_back();
        ret = ret->right;
        while (ret) {
            item.push_back(ret);
            ret = ret->left;
        }
        return result;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !item.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
