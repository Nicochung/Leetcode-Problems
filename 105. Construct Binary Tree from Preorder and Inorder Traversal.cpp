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
    int preIndex;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0;
        return treeFromPreInOrder(preorder,inorder, 0, inorder.size()-1);
    }
    
    TreeNode* treeFromPreInOrder(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        TreeNode *node = new TreeNode(preorder[preIndex++]);
        if (inStart == inEnd) return node;
        
        int splitIndex = serachInOrderIndex(inorder, inStart, inEnd, node->val);
        node->left = treeFromPreInOrder(preorder,inorder, inStart, splitIndex-1);
        node->right = treeFromPreInOrder(preorder,inorder, splitIndex + 1, inEnd);
        
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
