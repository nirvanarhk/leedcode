/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0 || nums.size() <3 ) return {};
        for (int k = 0; k < nums.size() -2; k++) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k-1]) continue;
            int target = 0 - nums[k], i = k +1, j = nums.size() -1;
            while ( i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[k],nums[i],nums[j]});
                    while(i < j && nums[i] == nums[i + 1]) i++;
                    while(i < j && nums[j] == nums[j - 1]) j--;
                    ++i; -- j;
                } else if (nums[i] + nums[j] < target) i++;
                else j --;
            }
        }
        if(res.size() > 0){
            return res;
        } else {
            return {};
        }
    }
};
// @lc code=end

