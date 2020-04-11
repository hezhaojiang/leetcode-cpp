/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
class Solution {
private:
    vector<int> result;
public:
    void backOrder(TreeNode* root)
    {
        if(!root) return;
        backOrder(root->left);
        backOrder(root->right);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        /* 递归 */
        // backOrder(root);
        /* 迭代 */
        stack<TreeNode*> node;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while(cur || !node.empty())
        {
            if(cur)
            {
                node.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = node.top();
                if(!cur->right)
                {
                    
                    result.push_back(cur->val);
                    node.pop();
                    pre = cur;
                    cur = cur->right;
                }
                else if(cur->right == pre)
                {
                    result.push_back(cur->val);
                    node.pop();
                    pre = cur;
                    cur = nullptr;
                }
                else
                {
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};
// @lc code=end
int main()
{
    TreeNode a(2);
    TreeNode b(3);
    TreeNode c(1);
    a.right = &b;
    b.right = &c;
    Solution solve;
    solve.postorderTraversal(&a);
    return 0;
}
