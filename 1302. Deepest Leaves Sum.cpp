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
    int deepestLeavesSum(TreeNode* root) {
        findDeepest(root, 1, root->val);
        return this->answer / 2;
    }
    
    void findDeepest(TreeNode* root, int depth, int preVal) {
        if (!root) {
            if (depth > this->deepest) {
                this->deepest = depth;
                this->answer = preVal;
            } else if (depth == this->deepest) {
                this->answer += preVal;
            }
            return;
        }
        findDeepest(root->left, depth+1, root->val);
        findDeepest(root->right, depth+1, root->val);
    }
private:
    int deepest{};
    int answer{};
};
