/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize)
{
    int** ret = NULL;
    *returnSize = 0;
    recursive(nums, 0, numsSize - 1, &ret, returnSize, numsSize);
    return ret;
}

void recursive(int* nums, int start, int end, int*** ret, int* returnSize, int numsSize)
{
    if (start == end) {
        for (int i = 0; i < *returnSize; i++) {
            if (memcmp(nums, (*ret)[i], numsSize * sizeof(int)) == 0)
                return;
        }
        int* t = malloc(sizeof(int) * numsSize);
        memcpy(t, nums, numsSize * sizeof(int));
        (*returnSize)++;
        *ret = realloc(*ret, sizeof(int*) * (*returnSize));
        (*ret)[*returnSize - 1] = t;
        return;
    }
    for (int i = start; i <= end; i++) {
        swap(nums, start, i);
        recursive(nums, start + 1, end, ret, returnSize, numsSize);
        swap(nums, start, i);
    }
}

void swap(int* nums, int m, int n)
{
    int t = *(nums + m);
    *(nums + m) = *(nums + n);
    *(nums + n) = t;
}
