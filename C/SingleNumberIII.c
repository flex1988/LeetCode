/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 2;
    int x = 0;
    for (int i = 0; i < numsSize; i++)
        x ^= nums[i];

    int mask = x & ~(x - 1);

    int n1 = 0;
    int n2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (mask & nums[i])
            n1 ^= nums[i];
        else
            n2 ^= nums[i];
    }
    int* ret = malloc(sizeof(int) * 2);
    ret[0] = n1;
    ret[1] = n2;
    return ret;
}
