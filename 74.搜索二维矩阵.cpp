/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int col = matrix[0].size();
        int p = 0, q = col -1;
        while(p < row && q >=0) {
            if (matrix[p][q] > target) {
                q -= 1;
            } else if (matrix[p][q] < target) {
                p += 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

