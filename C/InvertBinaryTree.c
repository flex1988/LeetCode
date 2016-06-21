/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL)
        return root;
    if (root->left != NULL)
        root->left = invertTree(root->left);
    if (root->right != NULL)
        root->right = invertTree(root->right);
    int temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}
