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
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> answer;
    //     postOrderHelper(root, answer);
    //     return answer;
    // }
    // void postOrderHelper(TreeNode *root, vector<int> &answer) {
    //     if (!root) return;
    //     postOrderHelper(root->left, answer);
    //     postOrderHelper(root->right, answer);
    //     answer.emplace_back(root->val);
    // }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<long int> s1;
        long int temp;
        while (root || !s1.empty()) {
            if (root) {
                s1.emplace((long int)root);
                root = root->left;
            } else {
                temp = s1.top();
                s1.pop();
                if (temp > 0) {
                    s1.emplace(-temp);
                    root = ((TreeNode *)temp)->right;
                } else {
                    answer.emplace_back(((TreeNode *)(-1*temp))->val);
                    root = nullptr;
                }
            }
        }
        return answer;
    }
};
