/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize)
{
    int** ret = NULL;
    *returnSize = 0;
    recursive(nums, 0, numsSize - 1, &ret, returnSize, numsSize);
    return ret;
}

void recursive(int* nums, int start, int end, int*** ret, int* returnSize, int numsSize)
{
    if (start == end) {
        (*returnSize)++;
        *ret = (int**)realloc(*ret, (*returnSize) * sizeof(int*));
        (*ret)[*returnSize - 1] = malloc(sizeof(int) * numsSize);
        memcpy((*ret)[*returnSize - 1], nums, numsSize * sizeof(int));
        return;
    }
    for (int i = start; i <= end; i++) {
        swap(nums + start, nums + i);
        recursive(nums, start + 1, end, ret, returnSize, numsSize);
        swap(nums + start, nums + i);
    }
}

void swap(int* m, int* n)
{
    int t = *m;
    *m = *n;
    *n = t;
}
