/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include <iostream>
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode pre_head(0);
        pre_head.next = head;

        ListNode* pre_curr = &pre_head;
        ListNode* next1 = nullptr;
        ListNode* next2 = nullptr;
        while (head) {
            next1 = head->next;
            if (next1) {
                next2 = next1->next;
                pre_curr->next = next1;
                next1->next = head;
                head->next = nullptr;
                pre_curr = head;
                next1 = next2;
            } else pre_curr->next = head;
            head = next1;
        }
        return pre_head.next;
    }
};
// @lc code=end

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    Solution solve;
    ListNode* head = solve.swapPairs(&a);
    while (head) {
        cout << "val = " << head->val << endl;
        head = head->next;
    }
    return 0;
}
