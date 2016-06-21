/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isNodeValid(struct TreeNode* root, int min, int max, bool isMin, bool isMax);
bool isValidBST(struct TreeNode* root)
{
    if (root == NULL)
        return true;
    if (!root->left && !root->right)
        return true;
    return isNodeValid(root, 0, 0, true, true);
}

bool isNodeValid(struct TreeNode* root, int min, int max, bool isMin, bool isMax)
{
    if ((root->val == min && !isMin) || (root->val == max && !isMax))
        return false;
    if ((root->val < min && !isMin) || (root->val > max && !isMax))
        return false;
    if (root->left && !isNodeValid(root->left, min, root->val, isMin, false))
        return false;
    if (root->right && !isNodeValid(root->right, root->val, max, false, isMax))
        return false;
    return true;
}
