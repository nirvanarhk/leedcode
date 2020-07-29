/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p0= dummy;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while(p1&&p2) {
            p0->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            p0=p1;
            p1 = p1->next;
            if(p1) {
                p2=p1->next;
            }
        }
        return dummy->next;
    }
 };
// @lc code=end

