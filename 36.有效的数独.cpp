/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         int rows[9][9]={0},cols[9][9]={0},cube[9][9]={0};
         for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                char num = board[i][j];
                if (num == '.')
                    continue;
                if (num-'0'>9 || num-'0'<1)
                    return false;
                if (rows[i][num-'1'] == 1) 
                    return false;
                else
                    rows[i][num-'1'] = 1;
                
                if (cols[j][num-'1'] == 1)
                    return false;
                else
                    cols[j][num-'1'] = 1;
                
                if (cube[3*(i/3)+j/3][num-'1'] == 1)
                    return false;
                else
                    cube[3*(i/3)+j/3][num-'1'] = 1;
                
            }
         }
         return true;
    }
};
// @lc code=end

