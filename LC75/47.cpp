//33. Search in Rotated Sorted Array
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (hi >= lo) {
            int md = lo + (hi - lo) / 2;
            if (nums[md] == target)
                return md;
            if (nums[md] >= nums[lo]) {
                if (target >= nums[lo] && target < nums[md])
                    hi = md - 1;
                else
                    lo = md + 1;
            }
            else {
                if (target <= nums[hi] && target > nums[md])
                    lo = md + 1;
                else
                    hi = md - 1;
            }
        }
        return -1;
    }
};