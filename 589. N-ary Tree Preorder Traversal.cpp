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
//     vector<int> preorder(Node* root) {
//         vector<int> ans;
//         helper(root, ans);
//         return ans;
//     }
    
//     void helper(Node* root, vector<int> &arr) {
//         if (!root) return;
//         arr.emplace_back(root->val);
//         for (int i = 0; i < root->children.size(); ++i) {
//             helper(root->children[i], arr);
//         }
//     }
    
    vector<int> preorder(Node* root) {
        if (!root) return {};
        stack<Node*> s1;
        vector<int> ans;
        s1.push(root);
        while(!s1.empty()) {
            Node *temp=s1.top();
            s1.pop();
            for (int i=temp->children.size()-1; i>=0; i--) 
                s1.emplace(temp->children[i]);
            ans.push_back(temp->val);
        }
        return ans;
    }
};
