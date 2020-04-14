/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
        if(!root) 
        {
            s.append("# ");
            return;
        }
        s.append(to_string(root->val) + " ");
        dfs(root->left, s);
        dfs(root->right, s);
        return;
    }
    void rebuild(TreeNode*& node, stringstream& ss)
    {
        string t;
        ss >> t;
        if(t[0] == '#')
        {
            node = nullptr;
            return;
        }
        int a = stoi(t);
        node = new TreeNode(a);
        rebuild(node->left, ss);
        rebuild(node->right, ss);
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
    TreeNode a(1);
    Codec solve;
    string astr = solve.serialize(&a);
    cout << astr << endl;
    TreeNode* pa = solve.deserialize(astr);
    cout << pa << endl;
    return 0;
}
