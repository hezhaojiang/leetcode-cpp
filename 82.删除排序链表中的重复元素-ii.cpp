/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode pre_head(0);
        pre_head.next = head;
        ListNode* pre_node = &pre_head;

        while (head) {
            bool needDel = false;
            ListNode* next = head->next;
            while (next) {
                if (next->val != head->val) break;
                else {
                    next = (head->next = next->next); // 删除结点
                    needDel = true;
                }
            }
            if (needDel) head = (pre_node->next = head->next);
            else pre_node = head, head = next;
        }
        return pre_head.next;
    }
};
// @lc code=end
