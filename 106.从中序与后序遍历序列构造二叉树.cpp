/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        return buildTreeiter(inorder, postorder, 0, len -1, 0, len -1);
    }
    TreeNode* buildTreeiter(vector<int>& inorder, vector<int>& postorder, int inleft, int inright, int posterleft, int posterright) {
        if (inleft > inright || posterleft > posterright) {
            return NULL;
        }
        TreeNode* node = new TreeNode();
        node->val = postorder[posterright];
        int idx = 0;
        for (idx = inleft; idx <= inright; idx++) {
            if (inorder[idx] == postorder[posterright]) {
                break;
            }
        } 
        node->left = buildTreeiter(inorder, postorder, inleft, idx-1, posterleft, posterright - 1 - (inright - idx));
        node->right = buildTreeiter(inorder, postorder, idx+1, inright, posterleft + idx - inleft,posterright-1);
        return node;
    }
};
// @lc code=end

