/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> arr1;
        if(root==NULL) return arr1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int a=q.size();
            vector<int> arr2;
            for(int i=0;i<a;++i){
                TreeNode* p=q.front();
                arr2.push_back(p->val);
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            arr1.push_back(arr2);
        }
        reverse(arr1.begin(),arr1.end());
        return arr1;
    }
};
// @lc code=end

