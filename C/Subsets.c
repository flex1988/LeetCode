/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int* nums, int numsSize, int** arr, int* index, int len, int*** ret, int* returnSize, int** columnSizes);
int cmp(const void* a, const void* b);

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize)
{
    int** ret = NULL;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i <= numsSize; i++) {
        int* arr = malloc(sizeof(int) * i);
        int index = 0;
        backtrack(nums, numsSize, &arr, &index, i, &ret, returnSize, columnSizes);
    }
    return ret;
}

void backtrack(int* nums, int numsSize, int** arr, int* index, int len, int*** ret, int* returnSize, int** columnSizes)
{
    if (len == *index) {
        (*returnSize)++;
        *ret = realloc(*ret, sizeof(int*) * (*returnSize));
        (*ret)[(*returnSize) - 1] = malloc(sizeof(int) * (len));
        *columnSizes = realloc(*columnSizes, sizeof(int) * (*returnSize));
        (*columnSizes)[(*returnSize) - 1] = len;
        memcpy((*ret)[(*returnSize) - 1], *arr, len * sizeof(int));
        return;
    }
    for (int i = *index; i < numsSize; i++) {
        if (*index > 0 && (*arr)[*index - 1] >= nums[i])
            continue;
        (*index)++;
        (*arr)[*index - 1] = nums[i];
        backtrack(nums, numsSize, arr, index, len, ret, returnSize, columnSizes);
        (*index)--;
    }
}

int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }
