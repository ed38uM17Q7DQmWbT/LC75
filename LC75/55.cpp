//198. House Robber
class Solution {
public:
    int helper(int subproblem, vector<int>& nums, vector<int>& memo) {
        if (memo[subproblem] != -1) {
            return memo[subproblem];
        }
        memo[subproblem] = max(nums[subproblem] + helper(subproblem + 2, nums, memo), helper(subproblem + 1, nums, memo));
        return memo[subproblem];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n - 1, -1);
        memo.push_back(nums.back());
        memo.push_back(0);
        return helper(0, nums, memo);
    }
};