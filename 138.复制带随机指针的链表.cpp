/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> old2new;
        old2new[nullptr] = nullptr;
        Node* ptr = head;
        while (ptr) {
            Node* next = ptr->next;
            Node* newNode = new Node(ptr->val);
            old2new[ptr] = newNode;
            ptr = next;
        }
        ptr = head;
        while (ptr) {
            Node* next = ptr->next;
            Node* newNode = old2new[ptr];
            newNode->next = old2new[ptr->next];
            newNode->random = old2new[ptr->random];
            ptr = next;
        }
        return old2new[head];
    }
};
// @lc code=end
