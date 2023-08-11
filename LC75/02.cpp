//724. Find Pivot Index
class Solution
{
public:
    int pivotIndex(vector<int>& nums)
    {
        int total = 0;
        int prefix = 0;

        for (int i = 0; i < nums.size(); i++)
            total += nums[i];

        for (int i = 0; i < nums.size(); i++) {
            if ((total - nums[i]) == 2 * prefix)
                return i;
            prefix += nums[i];
        }
        return -1;
    }
};