//39. Combination Sum
class Solution {
public:
    vector<vector<int>> solution;
    vector<int> dummy;
    void helper(int target, int start, vector<int>& candidates) {
        if (target == 0) {
            solution.push_back(dummy);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            dummy.push_back(candidates[i]);
            helper(target - candidates[i], i, candidates);
            dummy.pop_back();

        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(target, 0, candidates);
        return solution;
    }
};