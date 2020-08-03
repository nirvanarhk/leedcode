/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int a = x % 10;
        x = x / 10;
        int outx = a;
        while(x != 0) {
            a = x % 10;
            x = x / 10;
            if (outx > INT_MAX/10 || (outx == INT_MAX/10 && a > INT_MAX%10))
            {
                return 0;
            } else if (outx < INT_MIN/10 || (outx == INT_MIN/10 && a <= INT_MIN%10)) {
                return 0;
            }
            outx = outx * 10 + a;
        }
        return outx;
    }
};
// @lc code=end

