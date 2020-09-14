/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
#include<vector>
#include<stack>
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
#define MORRIS
class Solution {
private:
    vector<int> result;
public:
#ifdef RECURSIVE
    void midOrder(TreeNode* root) {
        if (!root) return;
        midOrder(root->left);
        result.push_back(root->val);
        midOrder(root->right);
    }
#endif
    vector<int> inorderTraversal(TreeNode* root) {
#ifdef RECURSIVE
        /* 递归 */
        //midOrder(root);
#endif
#ifdef ITERATE
        /* 迭代 */
        stack<TreeNode*> node;
        TreeNode* cur = root;
        while(cur || !node.empty()) {
            if(cur) {
                node.push(cur);
                cur = cur->left;
            }
            else {
                cur = node.top();
                result.push_back(cur->val);
                node.pop();
                cur = cur->right;
            }
        }
        return result;
#endif
#ifdef MORRIS
        if(!root) return result;
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                /* 如果存在左子树，则需要设置索引 */
                TreeNode* index = cur->left;
                while (index->right && index->right != cur)
                    index = index->right;
                
                if (!index->right) {
                    /* 首次寻找到索引，设置索引，继续遍历左子树 */
                    index->right = cur;
                    cur = cur->left;
                }
                else {
                    /* 非首次寻找到索引，说明左子树遍历完成，根据索引去遍历右子树 */
                    result.push_back(cur->val);
                    cur = cur->right;
                    /* 恢复索引 */
                    index->right = nullptr;
                }
            }
            else {
                /* 没有左子树 遍历右子树 */
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
#endif
    }
};
// @lc code=end
int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.right = &b;
    b.left = &c;
    Solution solve;
    solve.inorderTraversal(&a);
    return 0;
}

