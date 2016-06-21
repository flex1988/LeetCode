/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBalanced(struct TreeNode* root)
{
    if (!root)
        return true;
    if (getDepth(root->left) - getDepth(root->right) > 1 || getDepth(root->left) - getDepth(root->right) < -1)
        return false;
    else
        return isBalanced(root->left) && isBalanced(root->right);
}

int getDepth(struct TreeNode* root)
{
    if (!root)
        return 0;
    int left = getDepth(root->left);
    int right = getDepth(root->right);

    return left > right ? left + 1 : right + 1;
}
