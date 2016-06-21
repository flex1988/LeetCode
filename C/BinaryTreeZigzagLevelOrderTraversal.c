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
int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    if (!root)
        return NULL;
    *columnSizes = malloc(sizeof(int) * 100);
    *returnSize = 0;
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*));
    int index = 0;
    stack[index++] = root;
    int** ret = malloc(sizeof(int*) * 100);
    bool order = true;
    while (index) {
        struct TreeNode** tstack = malloc(sizeof(struct TreeNode*) * index * 2);
        int* arr = malloc(sizeof(int) * index);
        (*columnSizes)[*returnSize] = 0;
        int inner = 0;
        while (index--) {
            arr[(*columnSizes)[*returnSize]++] = stack[index]->val;
            if (order) {
                if (stack[index]->left)
                    tstack[inner++] = stack[index]->left;
                if (stack[index]->right)
                    tstack[inner++] = stack[index]->right;
            }
            else {
                if (stack[index]->right)
                    tstack[inner++] = stack[index]->right;
                if (stack[index]->left)
                    tstack[inner++] = stack[index]->left;
            }
        }
        index = inner;
        free(stack);
        stack = tstack;
        ret[(*returnSize)++] = arr;
        order = !order;
    }
    return ret;
}
