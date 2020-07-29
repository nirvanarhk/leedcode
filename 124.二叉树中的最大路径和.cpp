/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum(TreeNode* root) {
        maxSum = root->val;
        maxPathSumiter(root);
        return maxSum;
    }
    int maxPathSumiter(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftsum = maxPathSumiter(root->left);
        int rightsum = maxPathSumiter(root->right);
        int result = leftsum > rightsum ? leftsum : rightsum;
        int tempval = root->val;
        if (leftsum > 0) {
            tempval += leftsum;
        }
        if (rightsum > 0) {
            tempval += rightsum;
        }
        maxSum = maxSum > tempval ? maxSum : tempval;
        if (result > 0) {
            result += root->val;
        } else {
            result = root->val;
        }
        return result;
    }
    int maxSum;
};
// @lc code=end

