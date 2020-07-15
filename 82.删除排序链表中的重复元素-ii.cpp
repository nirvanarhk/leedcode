/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* p=dummy;
        while(p->next){
            ListNode* q=p->next;
            while(q&&q->val==p->next->val){
                q=q->next;
            }
            if(p->next->next==q) p=p->next;
            else p->next=q;
        }
        return dummy->next;
    }
};
// @lc code=end

