/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> Que;
        vector<int> item;
        int line;
        Que.push(root);
        while (!Que.empty()) {
            int count = Que.size();
            for (int i = 0; i < count; i++) {
                TreeNode* curQ = Que.front();
                if (curQ->left) Que.push(curQ->left);
                if (curQ->right) Que.push(curQ->right);
                item.push_back(curQ->val);
                Que.pop();
            }
            if (++line % 2 == 0) reverse(item.begin(), item.end());
            result.push_back(item);
            item.clear();
        }
        return result;
    }
};
// @lc code=end

