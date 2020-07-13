/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        for (int i = n -2; i>=0; i--) {
            if (nums[i] == 0) {
                int j = i - 1;
                for (; j >=0; j--) {
                    if(nums[j]>i - j) {
                        break;
                    }
                }
                if(j == -1) {
                    return false;
                }
            }
        }
        return true;
        
    }
};
// @lc code=end

