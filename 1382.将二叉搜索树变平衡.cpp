/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
 */
#include<vector>
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
    vector<int> result;
    TreeNode* halfDevide(vector<int>& nums, int start, int end)
    {
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if(start != mid) root->left = halfDevide(nums, start, mid - 1);
        if(mid != end) root->right = halfDevide(nums, mid + 1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        return halfDevide(nums, 0, nums.size() - 1);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return root;
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
                }
                else
                {
                    /* 非首次寻找到索引，说明左子树遍历完成，根据索引去遍历右子树 */
                    result.push_back(cur->val);
                    cur = cur->right;
                    /* 恢复索引 */
                    index->right = nullptr;
                }
            }
            else
            {
                /* 没有左子树 遍历右子树 */
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return sortedArrayToBST(result);
    }
};
// @lc code=end

