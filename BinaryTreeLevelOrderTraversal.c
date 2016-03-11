/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    if (!root)
        return NULL;
    *columnSizes = malloc(sizeof(int) * 1000);
    int** ret = malloc(sizeof(int*) * 1000);
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*) * 1000);
    int index = 0;
    *returnSize = 0;
    stack[index++] = root;

    while (index) {

        int* arr = malloc(sizeof(int) * index);
        struct TreeNode** inner = malloc(sizeof(struct TreeNode*) * 1000);
        int innerIndex = 0;
        for (int i = 0; i < index; i++) {
            arr[i] = stack[i]->val;
            if (stack[i]->left)
                inner[innerIndex++] = stack[i]->left;
            if (stack[i]->right)
                inner[innerIndex++] = stack[i]->right;
        }
        ret[(*returnSize)++] = arr;
        (*columnSizes)[*returnSize - 1] = index;
        free(stack);
        stack = inner;
        index = innerIndex;
    }
    return ret;
}
