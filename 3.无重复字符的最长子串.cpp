/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int len = s.length();
        map<char, int> charidx;
        int l = 0, r = 0;
        for(;r < len;r ++) {
            char c = s[r];
            if(charidx.find(c) != charidx.end()){
                // 确定左指针的位置
                int x = charidx[c];
                l = l > x + 1 ? l:(x+1);
            }
            charidx[c] = r;
            res = res > r - l + 1? res : r - l + 1;
        }
        return res;
    }
};
// @lc code=end

