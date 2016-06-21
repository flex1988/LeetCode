/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <math.h>

int countNodes(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    else if (root->left != NULL && root->right == NULL)
        return 2;
    int result = 0;
    int left = countHeight(root->left);
    int right = countHeight(root->right);
    if (left == right)
        result = pow(2, left + 1) - 1 + countNodes(root->right);
    else
        result = pow(2, right + 1) - 1 + countNodes(root->left);

    return result + 1;
}

int countHeight(struct TreeNode* root)
{
    int height = 0;
    while (root != NULL) {
        height++;
        root = root->left;
    }
    return height - 1;
}
