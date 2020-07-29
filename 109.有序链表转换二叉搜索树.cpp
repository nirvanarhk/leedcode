/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p = head;
        int n = 0;
        while(p) {
            p = p->next;
            n += 1;
        }
        return BuildBST(head, n);
    }
    TreeNode* BuildBST(ListNode* head, int n) {
        if (n == 0) {
            return NULL;
        }
        ListNode* p = head;
        ListNode* q = p;
        int idx = n / 2;
        while(idx > 0 && p != NULL) {
            q = p;
            p = p->next;
            idx--;
        }
        TreeNode* node = new TreeNode();
        node->val = p->val;
        node->left = BuildBST(head, n/2);
        node->right = BuildBST(p->next, n - n/2 -1);
        return node;
    }
};
// @lc code=end

