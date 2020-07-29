/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        return BuildBST(nums, 0, len - 1);
    }
    TreeNode* BuildBST(vector<int>& nums, int idxleft, int idxright) {
        if (idxleft > idxright) {
            return NULL;
        }
        int idx = (idxleft + idxright) / 2;
        TreeNode* node = new TreeNode();
        node->val = nums[idx];
        node->left = BuildBST(nums, idxleft, idx - 1);
        node->right = BuildBST(nums, idx + 1, idxright);
        return node;
    }
};
// @lc code=end

