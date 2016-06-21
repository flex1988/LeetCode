int lengthOfLIS(int* nums, int numsSize)
{
    int* rets = malloc(sizeof(int) * numsSize);
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        rets[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && rets[j] + 1 > rets[i])
                rets[i] = rets[j] + 1;
        }
        max = max > rets[i] ? max : rets[i];
    }
    return max;
}
