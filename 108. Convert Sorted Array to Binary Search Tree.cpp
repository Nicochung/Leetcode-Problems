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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = nullptr;
        int low = 0;
        int high = nums.size();
        int mid = low + (high - low) / 2;
        if (mid < high) {
            root = new TreeNode(nums[mid]);
            root->left = helper(nums, low, mid);
            root->right = helper(nums, mid+1, high);
        }
        return root;
    }
    
    TreeNode* helper(vector<int>& nums, int low, int high) {
        if (low >= high) return nullptr;
        int mid = low + (high - low) / 2;
        TreeNode *temp = new TreeNode(nums[mid]);
        temp->left = helper(nums, low, mid);
        temp->right = helper(nums, mid+1, high);
        return temp;
    }
};
