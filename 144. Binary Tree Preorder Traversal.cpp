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
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> answer;
//         preOrderHelper(root, answer);
//         return answer;
//     }
    
//      void preOrderHelper(TreeNode*root, vector<int> &answer) {
//         if (!root) return;       
//         answer.emplace_back(root->val);
//         preOrderHelper(root->left, answer);
//         preOrderHelper(root->right, answer);
//      }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> s1;
        while(root || !s1.empty()) {
            if (root) {
                answer.emplace_back(root->val);
                s1.emplace(root);
                root = root->left;
            } else{
                root = s1.top();
                s1.pop();
                root = root->right;
            }
        }
        return answer;
    }
};
