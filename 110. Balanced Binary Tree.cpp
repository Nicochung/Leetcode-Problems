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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        bool bf = abs(balanceFactor(root)) <= 1 ? true : false;
        return bf && isBalanced(root->left) && isBalanced(root->right);
    }
    
    int nodeHeight(TreeNode *root) {
        if (!root) return 0;
        int x = nodeHeight(root->left);
        int y = nodeHeight(root->right);
        return x > y ? x + 1: y + 1;
    }
    
    int balanceFactor(TreeNode *root) {
        if (!root) return 0;
        int x = root->left ? nodeHeight(root->left) : 0;
        int y = root->right ? nodeHeight(root->right) : 0;
        return x - y;
        
    }
};
