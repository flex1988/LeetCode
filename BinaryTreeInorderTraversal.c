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
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    int* left = NULL;
    int* right = NULL;
    int leftSize = 0;
    int rightSize = 0;
    if (root->left)
        left = inorderTraversal(root->left, &leftSize);
    if (root->right)
        right = inorderTraversal(root->right, &rightSize);
    int length = rightSize + leftSize + 1;
    *returnSize = length;
    int* ret = malloc(sizeof(int) * length);

    for (int i = 0; i < length; i++) {

        if (i >= 0 && i < leftSize)
            *(ret + i) = *(left + i);
        else if (i == leftSize) {
            *(ret + i) = root->val;
        }
        else if (i > leftSize && i < length)
            *(ret + i) = *(right + i - leftSize - 1);
    }
    return ret;
}
