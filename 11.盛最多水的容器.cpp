/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i = 0, j = len -1;
        int hleft = 0;
        int hright = 0;
        int h = 0;
        int area = 0;
        int maxarea = 0;
        while (i < j) {
            hleft = height[i];
            hright = height[j];
            h = hleft > hright? hright:hleft;
            area = h * (j - i);
            if (area > maxarea) {
                maxarea = area;
            }
            if (hleft < hright) {
                i += 1;
            } else {
                j -= 1;
            }
        }
        return maxarea;
    }
};
// @lc code=end

