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
//#define REVERSE1
//#define REVERSE2
//#define ITERATION
#define MORRIS
private:
    vector<int> result;
#ifdef MORRIS
    TreeNode* rightReverse(TreeNode* root) {
        TreeNode* head = nullptr;
        while(root)
        {
            TreeNode* next = root->right;
            root->right = head;
            head = root;
            root = next;
        }
        return head;
    }
    void printEdge (TreeNode* root) {
        root = rightReverse(root); // 逆
        TreeNode *head = root;
        while (head != nullptr) {
            result.push_back(head->val);
            head = head->right;
        }
        root = rightReverse(root); // 反逆
    }
#endif
#ifdef REVERSE1
    void backOrder(TreeNode* root)
    {
        if(!root) return;
        backOrder(root->left);
        backOrder(root->right);
        result.push_back(root->val);
    }
#endif

public:

    vector<int> postorderTraversal(TreeNode* root) {
#ifdef REVERSE1
        /* 递归 */
        backOrder(root);
        return result;
#endif
#ifdef REVERSE2
        vector<int> res;
        if(!root) return res;
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        res.push_back(root->val);
        return res;
#endif
#ifdef ITERATION
        /* 迭代 */
        stack<TreeNode*> node;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while (cur || !node.empty()) {
            if (cur) {
                node.push(cur);
                cur = cur->left;
            }
            else {
                cur = node.top();
                if (cur->right == nullptr || cur->right == pre) {
                    result.push_back(cur->val);
                    node.pop();
                    pre = cur;
                    cur = nullptr;
                }
                else cur = cur->right;
            }
        }
        return result;
#endif
#ifdef MORRIS
        if(!root) return result;
        TreeNode* cur = root;
        while(cur)
        {
            if(cur->left)
            {
                /* 如果存在左子树，则需要设置索引 */
                TreeNode* index = cur->left;
                while(index->right && index->right != cur)
                {
                    index = index->right;
                }

                if(!index->right)
                {
                    /* 首次寻找到索引，设置索引，继续遍历左子树 */
                    index->right = cur;
                    cur = cur->left;
                    continue;
                }
                else
                {
                    /* 非首次寻找到索引，说明左子树遍历完成，恢复索引 */
                    index->right = nullptr;
                    /* 逆序打印左子树的右子树 */
                    printEdge(cur->left);
                }
            }
            /* 没有左子树 遍历右子树 */
            cur = cur->right;
        }
        /* 逆序打印跟节点的右子树 */
        printEdge(root);
        return result;
#endif
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
