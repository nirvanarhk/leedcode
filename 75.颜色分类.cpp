/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p = 0, q = n -1, k = 0;
        int t = 0;
        while (k <= q) {
            if(nums[k] == 0) {
                t = nums[k];
                nums[k] = nums[p];
                nums[p] = t;
                p += 1;
            } else if (nums[k] == 2) {
                t = nums[k];
                nums[k] = nums[q];
                nums[q] = t;
                q -= 1;
                k -=1;
            }
            k += 1;
        }
    }
};
// @lc code=end

