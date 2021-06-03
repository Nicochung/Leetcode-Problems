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
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> answer;
//         inOrderHelper(root, answer);
//         return answer;
//     }
    
//     void inOrderHelper(TreeNode *root, vector<int> &answer) {
//         if (!root) return;
//         inOrderHelper(root->left, answer);
//         answer.emplace_back(root->val);
//         inOrderHelper(root->right, answer);
//     }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode *> s1;
        while (root || !s1.empty()) {
            if (root) {
                s1.emplace(root);
                root = root->left;
            } else {
                root = s1.top();
                s1.pop();
                answer.emplace_back(root->val);
                root = root->right;
            }
        }
        return answer;
    }
};
