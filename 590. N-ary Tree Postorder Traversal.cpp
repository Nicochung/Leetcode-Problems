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

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
    
    void helper(Node* root, vector<int> &arr) {
        if (!root) return;
        for (int i = 0; i < root->children.size(); ++i) {
            helper(root->children[i], arr);
        }
        arr.emplace_back(root->val);
    }
};
