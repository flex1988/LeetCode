/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int** columnSizes, int* returnSize)
{
    int** ret = NULL;
    int* comb = malloc(sizeof(int) * k);
    int combSize = 0;
    *returnSize = 0;
    recursion(k, 0, n, &comb, &combSize, &ret, returnSize, columnSizes);
    return ret;
}

void recursion(int left, int prev, int n, int** comb, int* combSize, int*** ret, int* returnSize, int** columnSizes)
{
    if (left == 0) {
        (*returnSize)++;
        *ret = realloc(*ret, sizeof(int*) * (*returnSize));
        (*ret)[(*returnSize) - 1] = malloc(sizeof(int) * (*combSize));
        *columnSizes = realloc(*columnSizes, sizeof(int) * (*returnSize));
        (*columnSizes)[(*returnSize) - 1] = *combSize;
        memcpy((*ret)[(*returnSize) - 1], *comb, (*combSize) * sizeof(int));
        return;
    }
    for (int i = prev + 1; i <= n; i++) {
        (*comb)[(*combSize)++] = i;
        recursion(left - 1, i, n, comb, combSize, ret, returnSize, columnSizes);
        (*combSize)--;
    }
}
