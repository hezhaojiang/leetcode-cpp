/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
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
class Codec {
private:
    void dfs(TreeNode* root, string& s)
    {
        if(!root) return;
        s.append(to_string(root->val) + " ");
        dfs(root->left, s);
        dfs(root->right, s);
        return;
    }
    void rebuild(TreeNode*& root, stringstream& ss)
    {
        string t;
        while(ss >> t)
        {
            int a = stoi(t);
            TreeNode* node = root;
            TreeNode* pre = nullptr;
            while(node)
            {
                pre = node;
                if(node->val < a) node = node->right;
                else node = node->left;
            }
            if(pre)
            {
                if(pre->val < a) pre->right = new TreeNode(a);
                else pre->left = new TreeNode(a);
            }
            else root = new TreeNode(a);
        }
        return;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        dfs(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        stringstream ss(data);
        rebuild(root, ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
int main()
{
    TreeNode a(2);
    TreeNode b(1);
    TreeNode c(3);
    a.left = &b;
    a.right = &c;
    Codec code;
    string s = code.serialize(&a);
    TreeNode* t = code.deserialize(s);
    return 0;
}
