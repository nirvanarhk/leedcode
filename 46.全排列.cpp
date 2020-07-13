/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ansSet;
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        Generate_Premutations(nums, n, n);
        return ansSet;
    }
    void Generate_Premutations(vector<int>& nums, int n, int k) {
        if (k == 1) {
            ansSet.push_back(nums);
            return;
        }
        for (int i = 0; i < k; i++)
        {
            int temp = nums[i];
            nums[i] = nums[k-1];
            nums[k-1] = temp;
            // 最后一位数字确定后，余下的是一个全排列的子问题
            Generate_Premutations(nums, n, k-1);
            
            // 恢复原数组
            temp = nums[i];
            nums[i] = nums[k-1];
            nums[k-1] = temp;
        }
    }
};
// @lc code=end

