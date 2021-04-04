/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode Guard(0);
        ListNode* ptr = &Guard;
        while (a && b) {
            if (a->val < b->val) ptr->next = a, a = a->next;
            else ptr->next = b, b = b->next;
            ptr = ptr->next;
        }
        ptr->next = a ? a : b;
        return Guard.next;
    }
};
// @lc code=end
