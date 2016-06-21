/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    if (root->left != NULL && root->right == NULL)
        return minDepth(root->left) + 1;
    else if (root->right != NULL && root->left == NULL)
        return minDepth(root->right) + 1;
    else if (root->left != NULL && root->right != NULL) {
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left > right)
            return right + 1;
        else
            return left + 1;
    }
    else
        return 1;
}
