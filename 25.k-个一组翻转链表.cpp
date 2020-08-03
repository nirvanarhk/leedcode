/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int len = 0;
        ListNode* p = head;
        while(p) {
            len += 1;
            p = p->next;
        }
        int count = len / k;
        ListNode* shorthead = dummy;
        ListNode* p0 = head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* start = head;
        ListNode* end = head;
        for(int n = 0; n < count; n++) {
            p0 = start;
            p1 = p0->next;
            for(int i = 1; i<k; i++) {       
                p2->next = p1->next;
                p1->next = p0;
                p0 = p1;
                p1 = p2->next;
            }
            //head->next = p1;
            
            
            if(n == 0) {
                dummy->next = p0;
            }
            if(n>0) {
                end->next = p0;
            }
            end = start;
            start = p1;
            //end = p0;
            //count -= 1;
            //break;
        }
        return dummy->next;
    }
};
// @lc code=end

