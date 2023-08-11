//704. Binary Search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lobnd = 0;
        int index = 0;
        int hibnd = nums.size() - 1;


        while (lobnd <= hibnd) {
            index = lobnd + ((hibnd - lobnd) / 2);
            if (nums[index] == target)
                return index;
            if (nums[index] > target) {
                hibnd = index;
                hibnd--;
            }
            if (nums[index] < target) {
                lobnd = index;
                lobnd++;
            }
        }
        return -1;
    }
};