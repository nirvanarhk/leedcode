/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ansSet;
        combinationSum2(ansSet, candidates, target, 0);
        return ansSet;
    }
    void combinationSum2(vector<vector<int>>& ansSet, vector<int>& candidates, int target, int startIndex) {
        if(target == 0) {
            ansSet.push_back(oneAns);
            return;
        }
        if(target < 0) return;
        for(int i = startIndex; i < candidates.size(); ++i) {
            if (target >= 0) {
                oneAns.push_back(candidates[i]);
                combinationSum2(ansSet, candidates, target-candidates[i], i);
                oneAns.pop_back();
            }
            else 
                break;
        }
    }
    vector<int> oneAns;
};
// @lc code=end

