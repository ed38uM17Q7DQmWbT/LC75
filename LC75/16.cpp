//235. Lowest Common Ancestor of a Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val;
        int qval = q->val;
        p = root;
        q = root;


        while (p == q) {
            if (pval < root->val)
                p = root->left;
            if (pval > root->val)
                p = root->right;


            if (qval < root->val)
                q = root->left;
            if (qval > root->val)
                q = root->right;

            if (p == q)
                root = p;
        }
        return root;
    }
};