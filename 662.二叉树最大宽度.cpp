/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
 */
#include<iostream>
#include<queue>
#include<algorithm>
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef unsigned long long uint_64;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        if (!root) return maxWidth;
        queue<pair<TreeNode*, uint_64>> Q;
        Q.push({root, 0});
        while (!Q.empty()) {
            int Count = Q.size();
            uint_64 minIndex = UINT64_MAX;
            uint_64 maxIndex = 0;
            for (int i = 0; i < Count; i++) {
                auto node = Q.front();
                Q.pop();
                if (node.first->left) Q.push({node.first->left, 2 * node.second + 1});
                if (node.first->right) Q.push({node.first->right, 2 * node.second + 2});
                if (node.second < minIndex) minIndex = node.second;
                if (node.second > maxIndex) maxIndex = node.second;
            }
            if (maxWidth < maxIndex - minIndex + 1) maxWidth = maxIndex - minIndex + 1;
        }
        return maxWidth;
    }
};
// @lc code=end

