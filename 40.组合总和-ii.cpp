/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ansSet;
        sort(candidates.begin(),candidates.end());
        combinationSum2(ansSet, candidates, target, 0);
        return ansSet;
    }
    void combinationSum2(vector<vector<int>>& ansSet, vector<int>& candidates, int target, int startIndex) {
        if(target == 0) {
            ansSet.push_back(oneAns);
            return;
        }
        if(target < 0 ) return;
        for(int i = startIndex; i < candidates.size() ; ++i) {
            if (target >= 0) {
                if(i > startIndex && candidates[i]==candidates[i-1])
                    continue;
                oneAns.push_back(candidates[i]);
                combinationSum2(ansSet, candidates, target-candidates[i], i+1);
                oneAns.pop_back();
            }
            else 
                break;
        }
    }
    vector<int> oneAns;
};
// @lc code=end

