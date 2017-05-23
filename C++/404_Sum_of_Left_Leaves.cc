/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root)
            return 0;
        return sumLeft(root->left) + sumRight(root->right);
    }

    int sumLeft(TreeNode *root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val + sumLeft(root->left) + sumRight(root->right);
        return sumLeft(root->left) + sumRight(root->right);
    }

    int sumRight(TreeNode *root) {
        if (!root)
            return 0;
        return sumLeft(root->left) + sumRight(root->right);
    }
};
