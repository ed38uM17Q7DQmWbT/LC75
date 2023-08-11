//108. Convert Sorted Array to Binary Search Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int hi, int lo) {
        if (lo > hi)
            return nullptr;
        int md = lo + (hi - lo) / 2;

        TreeNode* root = new TreeNode(nums[md]);
        root->left = helper(nums, md - 1, lo);
        root->right = helper(nums, hi, md + 1);
        return root;
    }


    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, nums.size() - 1, 0);
    }
};