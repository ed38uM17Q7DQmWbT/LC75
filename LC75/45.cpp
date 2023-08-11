//437. Path Sum III
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
    int solution = 0;
    unordered_map<long, int> dummy;


    void preorder(TreeNode* node, long currsum, int targsum) {
        if (node == nullptr)
            return;
        currsum += node->val;
        if (currsum == targsum)
            solution++;
        solution += dummy[currsum - targsum];
        dummy[currsum]++;
        preorder(node->left, currsum, targsum);
        preorder(node->right, currsum, targsum);
        dummy[currsum]--;
    }


    int pathSum(TreeNode* root, int targetSum) {
        preorder(root, 0, targetSum);
        return solution;
    }
};