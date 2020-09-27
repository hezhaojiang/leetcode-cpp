/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void SeqTraverse(Node* root) {
        while (root) {
            Node* level = root;
            Node* next = nullptr;
            Node* pre = nullptr;
            while (level) {
                if (pre && level->left) pre->next = level->left;
                if (level->left) pre = level->left;
                if (pre && level->right) pre->next = level->right;
                if (level->right) pre = level->right;
                if (!next) next = level->left?level->left:level->right;
                level = level->next;
            }
            root = next;
        }
        return;
    }
public:
    Node* connect(Node* root) {
        if(root) SeqTraverse(root);
        return root;
    }
};
// @lc code=end

