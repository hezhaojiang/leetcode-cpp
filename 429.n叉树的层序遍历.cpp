/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
 */
#include<vector>
#include<queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        vector<int> peace;
        if (!root) return result;
        queue<Node*> Q;
        Q.push(root);
        Q.push(nullptr);
        while (!Q.empty()) {
            Node* node = Q.front();
            Q.pop();
            if (node == nullptr) {
                result.push_back(peace);
                peace.clear();
                if(!Q.empty()) Q.push(nullptr);
                continue;
            }
            peace.emplace_back(node->val);
            for (auto & child : node->children) Q.push(child);
        }
        return result;
    }
};
// @lc code=end

