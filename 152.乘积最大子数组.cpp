/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mmax,premax,nowmax;
        int premin,nowmin;
        int n=nums.size();
        mmax=premax=premin=nums[0];
        for(int i=1;i<n;++i)
        {
            nowmax=max(nums[i],max(nums[i]*premax,nums[i]*premin));
            nowmin=min(nums[i],min(nums[i]*premax,nums[i]*premin));
            mmax=max(mmax,nowmax);
            premax=nowmax;
            premin=nowmin;
        }
        return mmax;
    }
};
// @lc code=end

