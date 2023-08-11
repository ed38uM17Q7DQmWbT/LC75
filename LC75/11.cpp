//589. N-ary Tree Preorder Traversal
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root)
            return{};


        vector<int> solution;
        stack<Node*> visitme;
        Node* temp = nullptr;
        visitme.push(root);


        while (!visitme.empty()) {
            temp = visitme.top();
            visitme.pop();
            solution.push_back(temp->val);


            if (!temp->children.empty())
                for (int i = temp->children.size(); i > 0; i--) {
                    visitme.push(temp->children[i - 1]);
                }
        }
        return solution;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/