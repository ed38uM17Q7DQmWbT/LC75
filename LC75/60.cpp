//16. 3Sum Closest
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int difference = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int lo = i + 1;
            int hi = nums.size() - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (abs(target - sum) < abs(difference)) {
                    difference = target - sum;
                }
                if (sum < target) {
                    lo++;
                }
                else {
                    hi--;
                }

            }
        }
        return target - difference;
    }
};