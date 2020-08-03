/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        int res = 0;
        int flag = 1;
        int i = 0;
        int x = 0;
        if (len == 0 || (str[0] != '+' && str[0] != '-' && str[0] > '9' && str[0] < '0')) {
            return res;
        }
        while (i < len) {
            if (str[i] == ' ') {
                i += 1;
            } else {
                break;
            }
        }
        if (str[i] == '+') {
            i +=1;
        } else if (str[i] == '-') {
            i += 1;
            flag = -1;
        }
        for (; i < len; i++) {
            x = str[i] - '0';
            if (x < 0 || x > 9) {
                break;
            }
            if (res > INT_MAX/10 || (res == INT_MAX/10 && x > INT_MAX%10))
            {
                return INT_MAX;
            } else if (res < INT_MIN/10 || (res == INT_MIN/10 && x*flag <= INT_MIN%10)) {
                return INT_MIN;
            }
            res = res * 10 + x * flag;
        }
        return res;
    }
};
// @lc code=end

