/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        return buildTreeiter(preorder, inorder, 0, len-1, 0);
    }
    TreeNode* buildTreeiter(vector<int>& preorder, vector<int>& inorder, int idxleft, int idxright, int preorderidx) {
        if (idxleft > idxright) {
            return NULL;
        }
        TreeNode* node = new TreeNode();
        node->val = preorder[preorderidx];
        int idx = 0;
        for (idx = idxleft; idx <= idxright; idx++) {
            if (inorder[idx] == preorder[preorderidx]) {
                break;
            }
        } 
        node->left = buildTreeiter(preorder, inorder, idxleft, idx-1, preorderidx + 1);
        node->right = buildTreeiter(preorder, inorder, idx+1, idxright, preorderidx + idx - idxleft + 1);
        return node;
    }
};
// @lc code=end

