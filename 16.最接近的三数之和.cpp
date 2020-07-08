/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 30000;
        int diffres = res - target;
        for (int k = 0; k < nums.size() -2; k++ ) {
            int i = k + 1;
            int j = nums.size() -1;
            while (i < j) {
                int temp = nums[i] + nums[j] + nums[k];
                if ( temp < target) {
                    i++;
                    if (target - temp < diffres) {
                        res = temp;
                        diffres = target - temp;
                    }
                } else if (temp > target) {
                    j--;
                    if (temp - target < diffres) {
                        res = temp;
                        diffres = temp - target;
                    }
                } else {
                    return target;
                }
            }
        }
        return res;
    }
};
// @lc code=end

