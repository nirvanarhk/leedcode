/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int tempres = nums[0];
        for (int i = 1; i < n; i++) {
            if (tempres <=0 ) {
                tempres = nums[i];
            }
            else {
                tempres += nums[i];
            }
            if (tempres > res) {
                res = tempres;
            }
        }
        return res;
        
    }
};
// @lc code=end

