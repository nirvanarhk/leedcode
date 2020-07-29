/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
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
    bool isBalanced(TreeNode* root) {
        tag = true;
        checkheight(root);
        return tag;
    }
    int checkheight(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int left = checkheight(root->left);
        int right = checkheight(root->right);
        int height = left > right ? left + 1 : right + 1;
        if(right - left >1 || left - right > 1) {
            tag = false;
        }
        return height;
    }
    bool tag;
};
// @lc code=end

