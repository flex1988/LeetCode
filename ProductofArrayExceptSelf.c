/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int* l2r = calloc(numsSize - 1, sizeof(int));
    int* r2l = calloc(numsSize - 1, sizeof(int));
    int* ret = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    l2r[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        l2r[i] = nums[i] * l2r[i - 1];
    }
    r2l[0] = nums[numsSize - 1];
    for (int i = 1; i < numsSize; i++) {
        r2l[i] = nums[numsSize - i - 1] * r2l[i - 1];
    }
    for (int i = 0; i < numsSize; i++) {
        if (i == 0)
            ret[i] = r2l[numsSize - 2];
        else if (i == numsSize - 1)
            ret[i] = l2r[numsSize - 2];
        else
            ret[i] = l2r[i - 1] * r2l[numsSize - i - 2];
    }
    return ret;
}
