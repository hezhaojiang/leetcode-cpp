/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        // 1. 找中点
        ListNode *slow = head, *fast = head, *mid = nullptr;
        while (fast) {
            if (!fast->next || !fast->next->next) break;
            fast = fast->next->next;
            slow = slow->next;
        }
        // 2. 分
        ListNode *left = head, *right = slow->next;
        slow->next = nullptr;
        left = sortList(left);
        right = sortList(right);
        // 3. 治
        ListNode guard(0);
        ListNode *node = &guard;
        while (left && right) {
            if (left->val <= right->val) node->next = left, left = left->next;
            else node->next = right, right = right->next;
            node = node->next;
        }
        while (left) node->next = left, left = left->next, node = node->next;
        while (right) node->next = right, right = right->next, node = node->next;
        return guard.next;
    }
};
// @lc code=end

