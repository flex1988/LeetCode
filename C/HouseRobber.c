int rob(int* nums, int numsSize)
{
    if (numsSize <= 0)
        return 0;

    int result1[numsSize];
    int result2[numsSize];

    for (int i = 0; i < numsSize; i++) {
        int money = 0;
        if (i == 0) {
            result1[0] = nums[0];
            result2[0] = 0;
        }
        else {
            result1[i] = result2[i - 1] + nums[i];
            result2[i] = result1[i - 1] > result2[i - 1] ? result1[i - 1] : result2[i - 1];
        }
    }

    return result1[numsSize - 1] > result2[numsSize - 1] ? result1[numsSize - 1] : result2[numsSize - 1];
}
