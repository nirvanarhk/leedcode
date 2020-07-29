/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int i = 0, j = 0;
        for (i = 0; i< len -1; i++) {
            for (j = i +1; j < len; j++) {
                if ((nums[i] + nums[j]) == target) {
                    vector<int> res = {i,j};
                    return res;
                }
            }
        }
        return {i,j};
    }
};
// @lc code=end

