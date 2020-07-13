/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ansSet;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        Generate_Premutations(nums, n, n);
        return ansSet;
    }
    void Generate_Premutations(vector<int>& nums, int n, int k) {
        if (k == 1) {
            ansSet.push_back(nums);
            return;
        }
        unordered_set<int> uniq;
        for (int i = 0; i < k;i++)
        {
            if (uniq.count(nums[i]))
                continue;
            int temp = nums[i];
            nums[i] = nums[k-1];
            nums[k-1] = temp;
            // 最后一位数字确定后，余下的是一个全排列的子问题
            Generate_Premutations(nums, n, k-1);
            
            // 恢复原数组
            temp = nums[i];
            nums[i] = nums[k-1];
            nums[k-1] = temp;
            uniq.insert(nums[i]);
            
        }
    }
};
// @lc code=end

