/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */
#include<iostream>
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        /* 哨兵节点 */
        ListNode newHead(0);
        ListNode* posIn = &newHead;
        while (head) {
            /* 找到第 k 个节点 */
            int index = 0;
            ListNode* knode = head;
            while (knode && ++index != k) knode = knode->next;
            if (index == k) { /* 存在 k 个节点 */
                ListNode* next = NULL;
                for (int i = 0; i < k; i++) {
                    next = head->next;
                    head->next = posIn->next;
                    posIn->next = head;
                    head = next;
                }
                while (posIn->next) posIn = posIn->next;
            }
            else { /* 剩余不足 k 个节点 */
                while (posIn->next) posIn = posIn->next;
                posIn->next = head;
                head = NULL;
            }
        }
        return newHead.next;
    }
};
// @lc code=end

