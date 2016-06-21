/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void recursive(struct TreeNode* root, int tmp, int* ret);
int sumNumbers(struct TreeNode* root)
{
    if (!root)
        return 0;
    int ret = 0;
    recursive(root, 0, &ret);
    return ret;
}

void recursive(struct TreeNode* root, int tmp, int* ret)
{
    if (!root)
        return 0;
    int result = 0;
    result += tmp * 10;
    result += root->val;
    int t = result;

    if (root->left)
        recursive(root->left, t, ret);
    if (root->right)
        recursive(root->right, t, ret);
    if (!root->left && !root->right)
        *ret += result;
}
