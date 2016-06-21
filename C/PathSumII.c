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
int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize)
{
    if (!root)
        return NULL;
    *returnSize = 0;

    if (root->val == sum && !root->left && !root->right) {
        int** ret = malloc(sizeof(int*));
        int* arr = malloc(sizeof(int));
        arr[0] = sum;
        ret[0] = arr;
        *columnSizes = malloc(sizeof(int));
        (*columnSizes)[0] = 1;
        *returnSize = 1;
        return ret;
    }
    int* left;
    int leftSize = 0;
    int** leftret = pathSum(root->left, sum - root->val, &left, &leftSize);
    if (leftSize != 0) {
        *returnSize += leftSize;
    }
    int* right;
    int rightSize = 0;
    int** rightret = pathSum(root->right, sum - root->val, &right, &rightSize);
    if (rightSize != 0) {
        *returnSize += rightSize;
    }
    int** ret = malloc(sizeof(int*) * (*returnSize));
    *columnSizes = malloc(sizeof(int) * (*returnSize));
    int len = *returnSize;
    for (int i = 0; i < len; i++) {
        if (i < leftSize) {
            int* arr = malloc(sizeof(int) * (left[i] + 1));
            arr[0] = root->val;
            memcpy(arr + 1, leftret[i], sizeof(int) * left[i]);
            (*columnSizes)[i] = left[i] + 1;
            ret[i] = arr;
        }
        else {
            int* arr = malloc(sizeof(int) * (right[i - leftSize] + 1));
            arr[0] = root->val;
            memcpy(arr + 1, rightret[i - leftSize], sizeof(int) * right[i - leftSize]);
            (*columnSizes)[i] = right[i - leftSize] + 1;
            ret[i] = arr;
        }
    }
    return ret;
}
