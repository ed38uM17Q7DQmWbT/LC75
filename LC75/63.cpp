//101. Symmetric Tree


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
    bool helper(TreeNode* lft, TreeNode* rgt) {
        if (lft == nullptr && rgt == nullptr)
            return true;
        if (lft == nullptr || rgt == nullptr)
            return false;
        if (lft->val != rgt->val)
            return false;
        return helper(lft->right, rgt->left) && helper(lft->left, rgt->right);
    }

    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
};