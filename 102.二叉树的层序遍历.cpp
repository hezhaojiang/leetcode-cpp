/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 */
#include<vector>
#include<queue>
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> Que;
        Que.push(root);
        while (!Que.empty()) {
            vector<int> item;
            int count = Que.size();
            for (int i = 0; i < count; i++) {
                TreeNode* curQ = Que.front();
                if (curQ->left) Que.push(curQ->left);
                if (curQ->right) Que.push(curQ->right);
                item.push_back(curQ->val);
                Que.pop();
            }
            result.push_back(std::move(item));
        }
        return result;
    }
};
// @lc code=end

