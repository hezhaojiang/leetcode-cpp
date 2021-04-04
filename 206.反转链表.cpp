/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
#include <iostream>
using namespace std;

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
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        return new_head;
    }
};
// @lc code=end

