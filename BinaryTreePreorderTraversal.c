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
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int left = 0;
    int right = 0;
    int* leftret;
    int* rightret;
    if (root->left)
        leftret = preorderTraversal(root->left, &left);
    if (root->right)
        rightret = preorderTraversal(root->right, &right);

    int length = left + right + 1;

    *returnSize = length;

    int* ret = malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            *(ret + i) = root->val;
        }
        else if (i > 0 && i <= left) {
            *(ret + i) = *(leftret + i - 1);
        }
        else if (i > left) {
            *(ret + i) = *(rightret + i - left - 1);
        }
    }
    return ret;
}
