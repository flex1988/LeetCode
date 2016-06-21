int maxSubArray(int* nums, int numsSize)
{
    int max = nums[0];
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        max = sum > max ? sum : max;
        sum = sum < 0 ? 0 : sum;
    }

    return max;
}
