/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next || k == 0)
            return head;
        ListNode* p = head, *q = nullptr, *node = head;
        int len = 0;
        while(p)
        {
            len++;
            p = p->next;
        }
        if(k == len || k%len == 0)
            return head;
        p = head;
        k = len - (k % len);
        while(p && k)
        {
            q = p;
            p = p->next;
            k--;
        }
        q->next = nullptr;
        ListNode* newHead = p;
        while(p->next)
            p = p->next;
        p->next = node;
        return newHead;

    }
};
// @lc code=end

