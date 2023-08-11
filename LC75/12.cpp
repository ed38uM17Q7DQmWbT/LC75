//102. Binary Tree Level Order Traversal
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return{};


        vector<vector<int>> solution;
        vector<int> row;
        queue<TreeNode*> visit_list;
        int rowctr = 1;
        visit_list.push(root);


        while (!visit_list.empty()) {
            if (visit_list.front()->left)
                visit_list.push(visit_list.front()->left);
            if (visit_list.front()->right)
                visit_list.push(visit_list.front()->right);
            row.push_back(visit_list.front()->val);
            visit_list.pop();
            rowctr--;
            if (rowctr == 0) {
                solution.emplace_back(row);
                row.clear();
                rowctr = visit_list.size();
            }
        }


        return solution;
    }
};

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