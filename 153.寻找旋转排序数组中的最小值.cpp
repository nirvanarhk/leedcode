/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len -1;
        int mid = 0;
        int res = 0;
        while(left <= right) {
            mid = (left+right) / 2;
            if ((right-left) <=2) {
                res = nums[left]<nums[right]?nums[left]:nums[right];
                res = nums[mid] < res ? nums[mid] : res;
                return res;
            }
            if (nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1]) {
                return nums[mid];
            }
            if (nums[mid] > nums[left]) {
                if (nums[right] > nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                right = mid -1;
            }
        }
        return -1;
    }
};
// @lc code=end

