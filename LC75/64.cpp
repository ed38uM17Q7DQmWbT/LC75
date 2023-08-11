//199. Binary Tree Right Side View


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
    void helper(TreeNode* root, vector<int>& solution, int depth) {
        if (root == nullptr)
            return;
        if (depth == solution.size())
            solution.push_back(root->val);
        helper(root->right, solution, depth + 1);
        helper(root->left, solution, depth + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> solution;
        helper(root, solution, 0);
        return solution;
    }
};