//1. Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int global) {
        unordered_map<int, int> dummy;
        vector<int> solution;
        int local = 0;


        for (int i = 0; i < nums.size(); i++) {
            local = global - nums[i];
            if (dummy.count(local)) {
                solution.push_back(dummy[local]);
                solution.push_back(i);
                return solution;
            }
            dummy.insert({ nums[i], i });
        }
        return { -1, -1 };
    }
};