/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode pre_head(0);
        pre_head.next = head;
        ListNode* nodeCur = &pre_head;
        while (nodeCur->next) {
            if (val == nodeCur->next->val) nodeCur->next = nodeCur->next->next;
            else nodeCur = nodeCur->next;
        }
        return pre_head.next;
    }
};
// @lc code=end

