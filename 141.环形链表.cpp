/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* p = head;
        ListNode* q = head->next;
        while (q) {
            if (p == q) {
                return true;
            }
            p = p->next;
            q = q->next;
            if(q == NULL) return false;
            q = q->next;
        }
        return false;
    }
};
// @lc code=end

