/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        /*
        ListNode* preNode = dummy;
        while (!head) {
            ListNode* curNode = head;
            head = head->next;
            if (preNode->val <= curNode->val) {
                preNode = curNode;
                continue;
            }
            preNode->next = curNode->next;
            ListNode* p = dummy;
            for (ListNode* p = dummy;)
        }
        */
        ListNode* tail = head;
        ListNode* k = head;
        ListNode* q = dummy;
        ListNode* p = head;
         while (tail && tail->next) {
            q = dummy;
            k = dummy;
            p = tail->next;
            if(tail->val < p->val) {
                tail = tail->next;
                continue;
            }
            while(k != tail) {
                if (k->val <= p->val) {
                    q = k;
                    k = k->next;
                    //break;
                } else {
                    break;
                }
            }
            tail->next = p->next;
            q->next = p;
            p->next = k;
            //tail = tail->next;
            //break;
        }
        return dummy->next;
    }
};
// @lc code=end

