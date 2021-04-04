/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        int result = 0;
        if (!root) return result;
        queue<TreeNode*> Que;
        Que.push(root);
        while (!Que.empty()) {
            int count = Que.size();
            for (int i = 0; i < count; i++) {
                TreeNode* curQ = Que.front();
                if (i == 0) result = curQ->val;
                if (curQ->left) Que.push(curQ->left);
                if (curQ->right) Que.push(curQ->right);
                Que.pop();
            }
        }
        return result;
    }
};
// @lc code=end

