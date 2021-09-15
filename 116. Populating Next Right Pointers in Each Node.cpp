/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // Node* connect(Node* root) {
    //     if (!root) return root;
    //     queue<Node*> q1;
    //     q1.emplace(root);
    //     int cnt{1}, cnt2{1};
    //     while (!q1.empty()) {
    //         Node *temp = q1.front();
    //         q1.pop();
    //         if (!temp) continue;
    //         q1.emplace(temp->left);
    //         q1.emplace(temp->right);
    //         if (cnt == cnt2) {
    //             cnt = 1;
    //             cnt2 *= 2;
    //         } else {
    //             ++cnt;
    //             temp->next = q1.front();
    //         }
    //     }
    //     return root;
    // }
    void connect(Node* root1, Node* root2) {
        if (!root1 && !root2) return;
        root1->next = root2;
        connect(root1->left, root1->right);
        connect(root1->right, root2->left);
        connect(root2->left, root2->right);
    }
    
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        connect(root->left, root->right);
        return root;
    }
};
