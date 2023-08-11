//152. Maximum Product Subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 1;
        int mini = 1;
        int solution = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int temp = maxi;
            maxi = max({ nums[i], temp * nums[i], mini * nums[i] });
            mini = min({ nums[i], temp * nums[i], mini * nums[i] });
            solution = max({ maxi, mini, solution });
        }
        return solution;
    }
};