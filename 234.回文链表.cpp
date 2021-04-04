/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> NodeStack;
        ListNode* cur = head;
        while (cur) {
            NodeStack.push(cur->val);
            cur = cur->next;
        }
        while (head) {
            if (NodeStack.top() != head->val) return false;
            NodeStack.pop();
            head = head->next;
        }
        return true;
    }
};
// @lc code=end
