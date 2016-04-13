/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b);
int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int** ret = NULL;
    int* arr = malloc(sizeof(int) * (target / candidates[0] + 1));
    int combSize = 0;
    backtrack(&arr, &combSize, 0, target, candidates, candidatesSize, columnSizes, &ret, returnSize);
    return ret;
}

void backtrack(int** combination, int* combSize, int sum, int target, int* candidates, int candidatesSize, int** columnSizes, int*** ret, int* returnSize)
{
    for (int i = 0; i < candidatesSize; i++) {
        if (i > 0 && candidates[i] == candidates[i - 1])
            continue;
        sum += candidates[i];
        if (sum < target) {
            (*combination)[(*combSize)++] = candidates[i];
            int t = *combSize;
            backtrack(combination, combSize, sum, target, candidates + i + 1, candidatesSize - i - 1, columnSizes, ret, returnSize);
            *combSize = t - 1;
        }
        else if (sum > target) {
            break;
        }
        else {
            (*combination)[*combSize] = candidates[i];
            (*returnSize)++;
            *ret = realloc(*ret, sizeof(int*) * (*returnSize));
            (*ret)[(*returnSize) - 1] = malloc(sizeof(int) * (*combSize + 1));
            *columnSizes = realloc(*columnSizes, sizeof(int*) * (*returnSize));
            (*columnSizes)[(*returnSize) - 1] = *combSize + 1;
            memcpy((*ret)[(*returnSize) - 1], *combination, sizeof(int) * (*combSize + 1));
        }
        sum -= candidates[i];
    }
}
int cmp(const void* a, const void* b) { return *((int*)a) - *((int*)b); }
