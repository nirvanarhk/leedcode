/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = head;
        ListNode* left = head;
        ListNode* right = head;
        for(int i = 0; i < n; i++) {
            right = right->next;
        }
        if(right == NULL) {
            return res->next;
        } 
        while(right->next != NULL) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return res;

    }
};
// @lc code=end

