/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root) {
            if(root->left) {
                TreeNode* mostright = root->left;
                while(mostright->right) mostright = mostright->right;
                mostright->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
        return;
        
       /*
       while (root != nullptr) {
            if (root->left != nullptr) {
                auto most_right = root->left; // 如果左子树不为空, 那么就先找到左子树的最右节点
                while (most_right->right != nullptr) most_right = most_right->right; // 找最右节点
                most_right->right = root->right; // 然后将跟的右孩子放到最右节点的右子树上
                root->right = root->left; // 这时候跟的右孩子可以释放, 因此我令左孩子放到右孩子上
                root->left = nullptr; // 将左孩子置为空
            }
            root = root->right; // 继续下一个节点
        }
        return;
        */
    }
};
// @lc code=end

