//543. Diameter of Binary Tree
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
    int height(TreeNode* node) {
        if (node == nullptr) {
            return -1;
        }


        int lheight = height(node->left);
        int rheight = height(node->right);
        return 1 + max(lheight, rheight);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }


        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = height(root->left) + height(root->right) + 2;


        return max(option1, max(option2, option3));
    }
};