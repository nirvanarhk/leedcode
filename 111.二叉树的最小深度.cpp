/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        int left = 0;
        int right = 0;
        int height = 0;
        if (root->left) {
            left = minDepth(root->left);
            height = left  + 1;
        }
        if (root->right) {
            right = minDepth(root->right);
            if (root->left) {
                height = height > right+1 ? right + 1: height;
            } else {
                height = right + 1;
            }
        }
        return height;
    }
};
// @lc code=end

