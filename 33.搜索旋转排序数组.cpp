/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int i = 0, j = len -1;
        int k = 0;
        while (i <= j) {
            k = (i + j) / 2;
            if (nums[k] == target) {
                return k;
            }
            if (nums[i] <= nums[k]) {
                if (nums[i] <= target && target < nums[k]) {
                    j = k -1;
                } else {
                    i = k + 1;
                }
            } else {
                if (nums[k] < target && target <= nums[j]) {
                    i = k + 1;
                } else {
                    j = k -1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

