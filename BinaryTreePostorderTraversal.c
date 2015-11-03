/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int left = 0;
    int right = 0;
    int* pleft = NULL;
    int* pright = NULL;
    if (root->left)
        pleft = postorderTraversal(root->left, &left);
    if (root->right)
        pright = postorderTraversal(root->right, &right);

    int length = left + right + 1;
    *returnSize = length;

    int* ret = malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        if (i == length - 1) {
            *(ret + i) = root->val;
        }
        else if (i >= 0 && i < left) {
            *(ret + i) = *(pleft + i);
        }
        else if (i >= left && i < right + left) {
            *(ret + i) = *(pright + i - left);
        }
    }
    return ret;
}
