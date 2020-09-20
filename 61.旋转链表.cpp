/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int length = 0;
        ListNode* node = head;
        while (++length) {
            if (node->next == nullptr) { node->next = head; break; }
            node = node->next;
        }
        int step = length - k % length;
        while (step--) node = node->next;
        head = node->next;
        node->next = nullptr;
        return head;
    }
};
// @lc code=end

