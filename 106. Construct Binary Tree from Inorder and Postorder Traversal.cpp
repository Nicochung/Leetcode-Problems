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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return treeFromInPostOrder(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
    TreeNode* treeFromInPostOrder(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;
        TreeNode *node = new TreeNode(postorder[postEnd]);
        if (inStart == inEnd) return node;
        
        int splitIndex = serachInOrderIndex(inorder, inStart, inEnd, node->val);
        node->left = treeFromInPostOrder(inorder,postorder, inStart, splitIndex-1, postStart, postStart + splitIndex - (inStart + 1));
        node->right = treeFromInPostOrder(inorder,postorder, splitIndex + 1, inEnd, postStart + splitIndex -inStart , postEnd-1);
        return node;
    }
    
    int serachInOrderIndex(vector<int> &inorder, int inStart, int inEnd, int data) {
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == data)
                return i;
        }
        return -1;
    }
};
