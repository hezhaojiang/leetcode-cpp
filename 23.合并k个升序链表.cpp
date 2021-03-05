/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
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
private:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if ((!a) || (!b)) return a ? a : b;
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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists, int l = 0, int r = -1) {
        if (r == -1) r = lists.size() - 1;
        if (r == l) return lists[r];
        if (r < l) return nullptr;
        int mid = l + r >> 1;
        ListNode* lst_1 = mergeKLists(lists, l, mid);
        ListNode* lst_2 = mergeKLists(lists, mid + 1, r);
        return mergeTwoLists(lst_1, lst_2);
    }
};
// @lc code=end
