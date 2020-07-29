/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    int sumNumbers(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int ans = 0;
        sumNumbersiter(root, 0, ans);
        //for(int i = 0; i < allans.size(); i++) {
        //    res += allans[i];
        //}
        return ans;
    }
    void sumNumbersiter(TreeNode* root, int res, int& ans) {
        if(root && !root->left && !root->right) {
            //allans.push_back(res * 10 + root->val);
            ans += res * 10 + root->val;
            return;
        }
        if (root->left) {
            sumNumbersiter(root->left, res * 10 + root->val, ans);
        }
        if (root->right) {
            sumNumbersiter(root->right, res * 10 + root->val, ans);
        }
        return;
    }
    //vector<int> allans;
};
// @lc code=end

