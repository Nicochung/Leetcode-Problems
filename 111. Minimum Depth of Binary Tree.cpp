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
private:
    int answer;
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        answer = INT_MAX;
        preOrder(root, 1);
        return answer;
    }
    
    void preOrder(TreeNode *root, int level) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (level < answer)
                answer = level;
            return;
        }
        preOrder(root->left, level+1);
        preOrder(root->right, level+1);
    }
};
