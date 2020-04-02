/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define SORT

#ifdef SORT
bool cmp(const ListNode* a, const ListNode* b)
{
    return a->val < b->val;
}
#endif

class Solution {
public:

#ifdef DIVIDE
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(!l1)
        {
            return l2;
        }

        ListNode* start = l1;

        while(l2)
        {
            ListNode* next2 = l2->next;
            while(l1)
            {
                if(l1->val > l2->val)
                {
                    l2->next = l1;
                    l1 = l2;
                    start = l2;
                    break;
                }
                if(nullptr == l1->next || l1->next->val > l2->val)
                {
                    l2->next = l1->next;
                    l1->next = l2;
                    break;
                }
                l1 = l1->next;
            }
            l2 = next2;
        }
        return start;
    }
#endif

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
#ifdef SORT
        std::vector<ListNode*> node_vec;
        for(int i = 0; i < lists.size(); i++)
        {
            ListNode* head = lists[i];
            while(head)
            {
                node_vec.push_back(head);
                head = head->next;
            }
        }
        if(0 == node_vec.size())
        {
            return nullptr;
        }

        std::sort(node_vec.begin(), node_vec.end(), cmp);
        
        for(int i = 1; i < node_vec.size(); i++)
        {
            node_vec[i - 1]->next = node_vec[i];
        }
        node_vec[node_vec.size() - 1]->next = nullptr;
        return node_vec[0];
#endif

#ifdef DIVIDE
        if(0 == lists.size())
        {
            return nullptr;
        }
        else if(1 == lists.size())
        {
            return lists[0];
        }
        else if(2 == lists.size())
        {
            return mergeTwoLists(lists[0], lists[1]);
        }
        else
        {
            int mid = lists.size()/2;
            std::vector<ListNode*> sub1_lists;
            std::vector<ListNode*> sub2_lists;

            for(int i = 0; i < lists.size(); i++)
            {
                if(i < mid)
                {
                    sub1_lists.push_back(lists[i]);
                }
                else
                {
                    sub2_lists.push_back(lists[i]);
                }
            }

            ListNode *l1 = mergeKLists(sub1_lists);
            ListNode *l2 = mergeKLists(sub2_lists);
            return mergeTwoLists(l1, l2);
        }
#endif  
    }
};
// @lc code=end

