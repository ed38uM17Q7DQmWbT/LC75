//46. Permutations
class Solution {
public:
    vector<vector<int>> solution;
    void helper(int n, int f, vector<int>& nums) {
        if (f == n) {
            solution.push_back(nums);
        }
        for (int i = f; i < n; i++) {
            swap(nums[f], nums[i]);
            helper(n, f + 1, nums);
            swap(nums[f], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums.size(), 0, nums);
        return solution;
    }
};