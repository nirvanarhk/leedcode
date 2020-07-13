/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        
        vector<int> nums;
        //将所有的数字都放在nums这个数组中
        for(int i = 1; i <= n; i++)
            nums.push_back(i);
        
        
        for(int j = 0; j < n; j++){
            int len = nums.size();
            //k如果（i-1）* (len - 1)!到i * (len - 1)!
            //那个str += nums[i - 1]; k -= (i - 1) * (len - 1)!
            for(int i = 1; i <= len; i++){
                int n = getMul(len - 1);
                if((i - 1)*n < k && k <= i * n){
                    char c = '0' + nums[i - 1];
                    res += c;
                    nums.erase(nums.begin() + (i - 1));
                    k -= (i - 1) * n;
                    break;
                }
            }
        }  
        return res;
    }
    int getMul(int n){
        int res = 1;
        for(int i = 2; i <= n; i++)
            res *= i;
        return res;
    }
};
// @lc code=end

