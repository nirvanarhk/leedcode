/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *dummy = new ListNode(0), *p = head, *q;
        dummy->next = head;
        int len = 0, step = 1;
        while (p) {
            len++;
            p = p->next;
        }
        while (step < len) {
            p = dummy;
            q = dummy->next;
            while(q) {
                ListNode *h1 = q;
                int step1 = step;
                while (step1 && q) {
                    q = q->next;
                    step1--;
                }
                if (step1) {
                    break;
                }
                ListNode *h2 = q;
                int step2 = step;
                while(step2 && q) {
                    q = q->next;
                    step2--;
                }
                int len1 = step, len2 = step-step2;
                while (len1 && len2) {
                    if (h1->val < h2->val) {
                        p->next = h1;
                        h1= h1->next;
                        len1--;
                    } else {
                        p->next = h2;
                        h2 = h2->next;
                        len2--;
                    }
                    p = p->next;
                }
                if (len1) {
                    p->next = h1;
                } else {
                    p->next = h2;
                }
                while(len1 > 0 || len2 > 0) {
                    p = p->next;
                    len1--;
                    len2--;
                }
                p->next = q;
            }
            step *=2;
        }
        return dummy->next;
    }
};
// @lc code=end

