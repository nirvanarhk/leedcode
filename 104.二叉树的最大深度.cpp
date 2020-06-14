/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        //int leftdepth = 0;
        //if(!root->left) {
        int    leftdepth = maxDepth(root->left);
        //}
        //int rightdepth = 0;
        //if(!root->right) {
        int    rightdepth = maxDepth(root->right);
        //}
        int res = 0;
        res = leftdepth > rightdepth?leftdepth+1:rightdepth+1;
        return res;
    }
};
// @lc code=end

