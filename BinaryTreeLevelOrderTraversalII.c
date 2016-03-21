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
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    if (!root)
        return NULL;
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*) * 2);
    *columnSizes = malloc(sizeof(int) * 1000);
    int** ret = malloc(sizeof(int*) * 1000);
    *returnSize = 0;
    int index = 0;
    stack[index++] = root;
    while (index) {
        struct TreeNode** tstack = malloc(sizeof(struct TreeNode*) * index * 2);
        int tindex = 0;
        int* res = malloc(sizeof(int) * index);
        (*columnSizes)[*returnSize] = 0;
        for (int i = 0; i < index; i++) {
            struct TreeNode* t = stack[i];
            if (t->left)
                tstack[tindex++] = t->left;
            if (t->right)
                tstack[tindex++] = t->right;
            res[(*columnSizes)[*returnSize]++] = t->val;
        }
        ret[(*returnSize)++] = res;
        free(stack);
        stack = tstack;
        index = tindex;
    }

    for (int i = 0; i < (*returnSize) / 2; i++) {
        int* t = ret[i];
        ret[i] = ret[*returnSize - i - 1];
        ret[*returnSize - i - 1] = t;
        int size = (*columnSizes)[i];
        (*columnSizes)[i] = (*columnSizes)[*returnSize - i - 1];
        (*columnSizes)[*returnSize - i - 1] = size;
    }

    return ret;
}
